"""
  Define a poly type
"""
abstract type AbstractPolygon end

struct MyPolyVar <: AbstractPolygon
        plist::Vector{MyPoint}
        nmax::Array{Int,1}
        ncur::Array{Int,1}
end

# Join two polygon sets of points together
# - creates a new poly
function join(poly1::MyPolyVar, poly2::MyPolyVar)
        ncur=length(poly1.plist) + length(poly2.plist)
        MyPolyVar(vcat(poly1.plist,poly2.plist),ncur)
end

# Append a point to a polygon
# - updates in place if there is free space, or otherwise 
# - allocates and returns larger poly with orginal points
# - copied over.
function append!(poly::MyPolyVar, p::MyPoint)
        ncur=poly.ncur[1]
        nmax=poly.nmax[1]
        if ncur+1 > nmax
           nmax=nmax+100
           poly=MyPolyVar(poly.plist,nmax)
        end
        poly.plist[ncur+1]=p
        poly.ncur[1]=ncur+1
        return poly
end

# Allocate a new poly from point list
# - allocate at least nmax points 
function MyPolyVar(p::Vector{MyPoint},nmax::Int)
        # Set total size
        ncur=length(p)
        nmax=Int(ceil(ncur/nmax))*nmax
        # Allocate and set default values
        plist=Vector{MyPoint}(undef,nmax)
        for i=1:nmax
          plist[i]=MyPoint(-999, -999)
        end
        poly=MyPolyVar(plist,[nmax],[ncur])
        # Set values for given points
        poly.plist[1:ncur]=p
        return poly
end

function area(poly::MyPolyVar)
        ta=0.
        p0=poly.plist[1]
        for i=3:poly.ncur[1]
                v1=poly.plist[i-1]-p0
                v2=poly.plist[i  ]-p0
                ta=ta+(v1.x*v2.y-v1.y*v2.x)*0.5
        end
        return ta
end

# Some inheritance
struct MyRectangle <: AbstractPolygon
        rpoly::MyPolyVar
        width::Float64
        height::Float64
end
