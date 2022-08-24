from typing import List
from Geometry.Point.Point import Point
from Geometry.Line.Line import Line

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
            print(f"[info] a polygon of {len(value)} vertices has been created")
            print("[warning] remember that vertices of a polygon are immutable")
            self._vertices = value
    
    @property
    def lines(self)->List[Point]:
        print("[warning] the vertices provided should be given in order")
        print("[warning] the vertices provided should represent a simple polygon")
        lines:List[Line] = []
        total_vertices:int = len(self.vertices)
        for i in range(0,total_vertices):
            lines.append(Line(p1=self.vertices[i],p2 = self.vertices[(i+1)%total_vertices]))
        return lines