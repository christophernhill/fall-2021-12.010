# Julia package manager can be used to create template for our 
# own package.
# We will use polgon area as an example.
#
# Start by creating a template for Package called MyPoly
#
using Pkg
Pkg.generate("MyPoly")
cd("MyPoly")
Pkg.activate(".")
import MyPoly
MyPoly.greet()
