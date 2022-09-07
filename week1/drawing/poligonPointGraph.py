from Geometry.Polygon.Polygon import Polygon
from Geometry.Line.Line import Line
from Geometry.Point.Point import Point
import numpy as np
import matplotlib.pyplot as plt 


def pointPolygonGraph(point:Point,polygon:Polygon,figsize=(15,15)):
    plt.figure(figsize = figsize)
    lines = polygon.lines
    max_x = max([ vertice.x_coordinate  for vertice in polygon.vertices ])
    belongs = "does not belong"
    if polygon.is_inside(point=point):
        belongs = "belongs"

    for line in lines:
        p1 = line.p1
        p2 = line.p2
        plt.plot([p1.x_coordinate,p2.x_coordinate],[p1.y_coordinate,p2.y_coordinate],marker = 'x',markersize=10)
    #plt.plot([last_vertice.x_coordinate,first_vertice.x_coordinate],[last_vertice.y_coordinate,first_vertice.y_coordinate],marker = 'x')
    plt.axhline(y=point.y_coordinate,xmin=point.x_coordinate,xmax=max_x+10,linewidth=4)
    plt.scatter(point.x_coordinate,point.y_coordinate,s = 70)
    
    #ax.plot([last_vertice.x_coordinate,first_vertice.x_coordinate],[last_vertice.y_coordinate,last_vertice.y_coordinate])
    plt.title(f"week1 - problem graph, polygon of {len(polygon.vertices)} vertices\npoint {belongs} to the polygon")    
    plt.show()

def countryPolygonGraph(polygon:Polygon,number_of_arbitrary_points:int,figsize=(15,15)):
    plt.figure(figsize = figsize)
    lines = polygon.lines      
    x_coordinates = [point.x_coordinate for point in polygon.vertices] + [polygon.vertices[0].x_coordinate]
    y_coordinates = [point.y_coordinate for point in polygon.vertices] + [polygon.vertices[0].y_coordinate]

    min_x = min(x_coordinates)
    max_x = max(x_coordinates)

    min_y = min(y_coordinates)
    max_y = max(y_coordinates)

    arbitray_x = np.random.uniform(min_x,max_x,size=(number_of_arbitrary_points,))    
    arbitray_y = np.random.uniform(min_y,max_y,size=(number_of_arbitrary_points,))
    
    points = [Point(coordinate[0],coordinate[1]) for coordinate in zip(arbitray_x,arbitray_y)]
    
    for point in points:
        try:
            if polygon.is_inside(point=point):                
                plt.plot(point.x_coordinate,point.y_coordinate,marker='o', markersize=8,markerfacecolor='red')
                #print("inside")
            else:                
                plt.plot(point.x_coordinate,point.y_coordinate, marker='o', markersize=8,markerfacecolor='green')
                #print("outside")
        except ValueError as ve:
            print(f"[error] value error with exception {ve}")

    plt.plot(x_coordinates,y_coordinates)
    #plt.scatter(arbitray_x,arbitray_y)    

    # for line in lines:
    #     p1 = line.p1
    #     p2 = line.p2
    #     plt.plot([p1.x_coordinate,p2.x_coordinate],[p1.y_coordinate,p2.y_coordinate])
    
    # for i in range(number_of_arbitrary_points):
    #     x_rand_coordinate = arbitray_x[i]
    #     y_rand_coordinate = arbitray_y[i]
    #     plt.scatter(x_rand_coordinate,y_rand_coordinate)
    # plt.title(f"week1 - problem graph, polygon of {len(polygon.vertices)} vertices")
    plt.show()
