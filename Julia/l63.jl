"""
     l63!(du,u,p,t)

 Steps forward the Lorenz63 equations for time `t`. 
 Prognostic variables x, y, z are defined as
 elements 1, 2 and 3 of vector `u` and with parameters
 σ, ρ and β defined as elements of vector `p`.
 Elements of du are set to dxdt, dydt and dzdt respectively.

```
 julia> using DifferentialEquations, Plots
 julia> u0=[1.,0.,0.]
 julia> p=[10.,28.,8/3]
 julia> tspan=(0.,100.)
 julia> prob=ODEProblem(l63!,u0,tspan,p)
 julia> sol=solve(prob)
 julia> plot(sol,vars=(1,2,3))
```

"""
function l63!(du,u,p,t)
        x, y, z=u
        σ, ρ, β=p

        dxdt=σ*(y-x)
        dydt=ρ*x-x*z-y
        dzdt=x*y-β*z

        du[1], du[2], du[3]=
        dxdt , dydt,  dzdt
        return
end
