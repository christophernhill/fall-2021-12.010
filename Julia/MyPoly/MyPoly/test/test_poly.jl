using MyPoly
p1=MyPoint(0,0)
p2=MyPoint(1,0)
p3=MyPoint(1,1)
p4=MyPoint(0,1)
p5=MyPoint(0,0)
poly1=MyPolyVar([p1,p2,p3,p4,p5],10)
a=area(poly1)
println(a)
