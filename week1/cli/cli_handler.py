from cli.constants import EXAMPLES_PATH,POLYGON_NAME,POINT_NAME , COUNTRIES_PATH , NUMBER_OF_ARBITRARY_POINTS
from Geometry.Polygon.Polygon import Polygon
from Geometry.Point.Point import Point
from drawing.poligonPointGraph import pointPolygonGraph , countryPolygonGraph


def handler(example,examples_path=EXAMPLES_PATH,polygon_name=POLYGON_NAME,point_name = POINT_NAME):
    
    polygon_path = examples_path+str(example)+"/"+polygon_name
    point_path = examples_path+str(example)+"/"+point_name
    polygon_points = []

    with open(polygon_path) as f:
        polygon_raw_points = f.readlines()

    with open(point_path) as f:
        line = f.readlines()

    line = line[0]
    point = Point(float(line.split(",")[0]),float(line.split(",")[1]))

    for raw_point in polygon_raw_points:
        points_list = raw_point.split(",")
        x_coordinate = float(points_list[0])
        y_coordinate = float(points_list[1])
        polygon_points.append(Point(x_coordinate=x_coordinate,y_coordinate=y_coordinate))
    
    polygon = Polygon(vertices=polygon_points)
    pointPolygonGraph(point=point,polygon=polygon)

def country_handler(country,country_path = COUNTRIES_PATH ):
    polygon_path = country_path+str(country) + ".txt"
    
    polygon_points = []

    with open(polygon_path) as f:
        polygon_raw_points = f.readlines()
    
    for raw_point in polygon_raw_points:
        points_list = raw_point.split(",")
        x_coordinate = float(points_list[0])
        y_coordinate = float(points_list[1])
        polygon_points.append(Point(x_coordinate=x_coordinate,y_coordinate=y_coordinate))
    
    polygon = Polygon(vertices=polygon_points)
    countryPolygonGraph(polygon=polygon,number_of_arbitrary_points=NUMBER_OF_ARBITRARY_POINTS)