#
# hand dask setup (using screen)
#   $ dask-scheduler
#   $ dask-worker --nprocs 30 --memory-limit 2GB --nthreads 2 tcp://127.0.0.1:8786
#
# ffmpeg command
#   $ ffmpeg -r 48 -s 1920x1080 -i fig-%06d.png -b:v 16M -pix_fmt yuv420p -r 24 foo.mp4
#
import xarray as xr
from pytictoc import TicToc
t = TicToc()
t.tic()
mur_sst = xr.open_zarr('https://mur-sst.s3.us-west-2.amazonaws.com/zarr-v1',consolidated=True)
t.toc('Scanning zarr directories took')

print(mur_sst)
print(mur_sst.analysed_sst.data.blocks[0,0,0])

from dask.distributed import Client
client = Client('tcp://127.0.0.1:8786')


ds=mur_sst.analysed_sst
mask_lon=(ds.lon >= -71.5) & ( ds.lon <= -68)
mask_lat=(ds.lat >=  41) & ( ds.lat <=  43)
import dask
with dask.config.set(**{'array.slicing.split_large_chunks': False}):
    ds_masked=ds.where(mask_lon & mask_lat, drop=True)

# Get one year of data for region
t.tic()
# sst_patches=ds_masked.sel(time=slice('2002-06-01','2007-06-01')).compute()
sst_patches=ds_masked.compute()
t.toc('Loading one year of data took')
# sst_patches=ds_masked.compute()
# t.toc('Loading all years of data took')

import numpy as np
t.tic()
sst_min=np.nanmin( sst_patches-273)
sst_max=np.nanmin( sst_patches-273)
sst_avg=np.nanmean(sst_patches-273)
sst_std=np.nanstd( sst_patches-273)
t.toc('Getting stats took')

import matplotlib.pyplot as plt
import matplotlib
cmap = plt.cm.get_cmap("gist_ncar")
# cmap = plt.cm.get_cmap("prism")

# from celluloid import Camera

mn=sst_avg
mv=sst_std
cr=2.5
# fig1, ax2 = plt.subplots(constrained_layout=True)
fig1 = plt.figure(figsize=(9,5))
ax2  = plt.axes()
# camera=Camera(fig1)

for i in [*range(0,sst_patches.shape[0])]:
# for i in [*range(0,60)]:
# for i in [*range(0,10)]:
    fig1 = plt.figure(figsize=(9,5))
    ax2  = plt.axes()
    CS=ax2.contourf(sst_patches.lon,sst_patches.lat,sst_patches[i,:,:]-273,50,vmax=mn+cr*mv,vmin=mn-cr*mv,cmap=cmap);
    CS2 = ax2.contour(CS, levels=CS.levels[::4], colors='k', origin='lower')
    if i >= 0:
        cs=matplotlib.cm.ScalarMappable(cmap=plt.cm.get_cmap("gist_ncar"))
        cs.set_clim( (mn-cr*mv,mn+cr*mv ) )
        cbar=fig1.colorbar(cs)
        axc=fig1.axes[1]
    else:
        cbar=fig1.colorbar(cs,cax=axc)
    cbar.add_lines(CS2)
    ttl="SST, %s"%(sst_patches.time[i].data)
    print(ttl)
    ax2.text( -70.8, 43.05, ttl );
    print(i)
    fn="fig-%6.6d.png"%(i)
    plt.savefig(fn)
    # camera.snap()

# animation=camera.animate()
plt.close()
# animation.save('foo.mp4',fps=40)
