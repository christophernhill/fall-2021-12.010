"""
  Define a point type
"""
struct MyPoint
        x::Float64
        y::Float64
end

Base.:+(p1::MyPoint,p2::MyPoint) = MyPoint( p1.x+p2.x, p1.y+p2.y )

Base.:-(p1::MyPoint,p2::MyPoint) = MyPoint( p1.x-p2.x, p1.y-p2.y )

function MyPoint(p::MyPoint)
        MyPoint(p.x, p.y)
end


