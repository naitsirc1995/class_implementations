from typing import List
from Geometry.Point.Point import Point

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
            print(f"[info] a polygon of {len(value)} has been created")
            print("[warning] remember that vertices of a polygon are immutable")
            self._vertices = value