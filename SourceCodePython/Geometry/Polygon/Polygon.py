from typing import List
from Geometry.Point.Point import Point
from Geometry.Line.Line import Line
import numpy as np

class Polygon:

    _vertices:List[Point] = None    

    def __init__(self,vertices:List[Point]=None) -> None:
        self.vertices = vertices

    @property
    def vertices(self) -> List[Point]:
        return self._vertices
    
    @vertices.setter
    def vertices(self,value:List[Point]) -> None:
        if len(value)  < 3:
            raise ValueError("[error] at least 3 points are needed for making a polygon")
        elif self._vertices:
            raise ValueError("[error] polygon already has points defined")            
        else:
            #print(f"[info] a polygon of {len(value)} vertices has been created")
            #print("[warning] remember that vertices of a polygon are immutable")
            self._vertices = value
    
    @property
    def lines(self)->List[Line]:
        #print("[warning] the vertices provided should be given in order")
        #print("[warning] the vertices provided should represent a simple polygon")
        lines:List[Line] = []
        total_vertices:int = len(self.vertices)
        for i in range(0,total_vertices):
            lines.append(Line(p1=self.vertices[i],p2 = self.vertices[(i+1)%total_vertices]))
        return lines
    
    def is_in_boundary(self,point:Point)->bool:
        for line in self.lines:
            if line.is_between_points(line_point_1=line.p1,line_point_2 = line.p2,point=point):
                return True
        return False
    
    def count_intersections_point_ray(self,point:Point)->int:
        if self.is_in_boundary(point):
            raise ValueError(f"[error] point {point} given belongs to the boundary")
        elif point in self.vertices:
            raise ValueError(f"[error] point {point} given is a vertice")
        else:
            final_count = 0
            ray = Line(p1=point,slope=0)
            total_lines = len(self.lines)
            #poligon_lines = [line for line in self.lines if min(line.p1.y_coordinate,line.p2.y_coordinate) <= point.y_coordinate and max(line.p1.y_coordinate,line.p2.y_coordinate) >= point.y_coordinate]
            #poligon_lines = [line for line in self.lines if min(line.p1.y_coordinate,line.p2.y_coordinate) <= point.y_coordinate and max(line.p1.y_coordinate,line.p2.y_coordinate) >= point.y_coordinate]
            for i in range(total_lines):
                
                poligon_line:Line = self.lines[i]                
                vertex1 = poligon_line.p1
                vertex2 = poligon_line.p2
                if max(poligon_line.p1.x_coordinate,poligon_line.p2.x_coordinate) < point.x_coordinate:
                    continue
                elif poligon_line.is_horizontal():
                    continue
                elif np.abs(vertex1.y_coordinate - point.y_coordinate) == 0:
                    augmenter = self.count_vertex_intersections(vertex1,self.lines[(i-1)%total_lines],poligon_line)
                    final_count+= augmenter
                    
                elif  np.abs(vertex2.y_coordinate - point.y_coordinate) == 0:
                    augmenter = self.count_vertex_intersections(vertex1,poligon_line,self.lines[(i+1)%total_lines])
                    final_count+=augmenter
                    
                else:
                    if poligon_line.is_vertical():
                        x_intersection = poligon_line.point.x_coordinate
                    else:
                        x_intersection = (point.y_coordinate - poligon_line.y_intersection)/poligon_line.slope
                    if min(poligon_line.p1.y_coordinate,poligon_line.p2.y_coordinate) < point.y_coordinate  and max(poligon_line.p1.y_coordinate,poligon_line.p2.y_coordinate) > point.y_coordinate and x_intersection > point.x_coordinate:                        
                        final_count+=1                        
                                             
                    
            #print(f"final count {final_count}")
            print(f"[info] ({point.x_coordinate},{point.y_coordinate}) total number of intersects {final_count}")
            return final_count

    
    def count_vertex_intersections(self,vertex:Point,previous_line:Line,next_line:Line)->int:
        if previous_line.is_horizontal() or next_line.is_horizontal():
            return 0
        else:
            p1:Point = previous_line.p1 if previous_line.p1 != vertex else previous_line.p2
            p2:Point = next_line.p1 if next_line.p1 != vertex else next_line.p2

            if (p1.y_coordinate - vertex.y_coordinate > 0 and p2.y_coordinate - vertex.y_coordinate > 0) or (p1.y_coordinate - vertex.y_coordinate < 0 and p2.y_coordinate - vertex.y_coordinate < 0):
                return 0 
            else:                
                print(f"[info] final count was augmented with vertex {vertex}")
                return 1


    def is_inside(self,point:Point) -> bool:       
        print(f"{point} with counts {self.count_intersections_point_ray(point=point)%2}")
        return self.count_intersections_point_ray(point=point)%2 == 0