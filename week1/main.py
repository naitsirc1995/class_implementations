from Geometry.Point.Point import Point
from Geometry.Polygon.Polygon import Polygon
from Geometry.Line.Line import Line


def main():
    myPoint1 = Point(1,2)
    myPoint2 = Point(2,3)
    pol = Polygon([myPoint1,myPoint2,myPoint2])
    line = Line()


if __name__ == '__main__':
    main()