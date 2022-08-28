from Geometry.Polygon.Polygon import Polygon
from Geometry.Line.Line import Line
from Geometry.Point.Point import Point
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
