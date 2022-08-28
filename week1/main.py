from Geometry.Point.Point import Point
from Geometry.Polygon.Polygon import Polygon
from Geometry.Line.Line import Line
from drawing.poligonPointGraph import pointPolygonGraph
from cli.cli import parseArguments

def main():
    #myPoint1 = Point(1,-1)
    #myPoint2 = Point(0,0)
    #myPoint3 = Point(0, 1)
    #pol = Polygon([myPoint1,myPoint2,myPoint3])
    #testingPoint = Point(0.2,1/8)
    parseArguments()
    


if __name__ == '__main__':
    main()