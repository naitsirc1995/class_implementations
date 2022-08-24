from Geometry.Point.Point import Point
from Geometry.Polygon.Polygon import Polygon
from Geometry.Line.Line import Line

def main():
    myPoint1 = Point(0,0)
    myPoint2 = Point(0,1)
    myPoint3 = Point(1,0)
    pol = Polygon([myPoint1,myPoint2,myPoint3])
    print(pol.lines)
    line = Line(p1=Point(0,1),p2=Point(1,1))
    print(line.belongs(Point(2,3)))


if __name__ == '__main__':
    main()