#
# To set up 
#
#   module load anaconda/2021a
#   module load cuda/11.3
#   pip install --user pycuda
#
# Add 
#    module load cuda/11.3
#    into
#    ~/.jupyter/llsc_notebook_bashrc
#    to  make Notebooks work with pycuda.
#   
#
import pycuda.driver as cuda
import time
import numpy
import pycuda.autoinit
import pycuda.gpuarray as gpuarray
import sys

nel=int(sys.argv[1])

# Small array
a_cpu = numpy.zeros((nel,)).astype(numpy.float32)+1.
b_cpu = numpy.zeros((nel,)).astype(numpy.float32)+1.
a_gpu = gpuarray.to_gpu(a_cpu)
b_gpu = gpuarray.to_gpu(b_cpu)

c_gpu = a_gpu+b_gpu
start=time.perf_counter()
c_gpu = a_gpu+b_gpu
end=time.perf_counter()
gpu_time=end-start

c_cpu = a_cpu+b_cpu
start=time.perf_counter()
c_cpu = a_cpu+b_cpu
end=time.perf_counter()
cpu_time=end-start
