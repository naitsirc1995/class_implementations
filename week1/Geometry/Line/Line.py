from xmlrpc.client import boolean
from Geometry.Point.Point import Point

class Line:

    _p1:Point = None
    _p2:Point = None 
    _slope:Point = None 
    _y_intersection:Point = None 

    def __init__(self,p1:Point=None,p2:Point=None,slope:float=None,y_intersection:float=None) -> None:

        if not p1 and not p2 and not slope and not y_intersection:
            raise ValueError("[error] no information provided to make a line")
        
        if not p1 and not p2 and not slope and y_intersection:
            raise ValueError("[error] line y_intersection needed")
        
        if not p1 and not p2 and slope and not y_intersection:
            raise ValueError("[error] y_intersection needed to make a line")
        
        if p1 and not p2 and not slope and not y_intersection:
            raise ValueError("[error] a second point or a slope is needed to form a line")

        if not p1 and p2 and not slope and not y_intersection:
            raise ValueError("[error] a second point or a slope is needed to form a line")
        
        else:
            pass
        

    def is_vertical(self)->boolean:
        if self._p1 and self._p2:
            return (self._p1.x_coordinate == self._p2.x_coordinate) or (self.slope == float('inf'))
        
            

    @property
    def slope(self)->float:
        return self._slope
    
    @slope.setter
    def slope(self,slope_value:float,y_intersection:float = None,p1_value:Point=None,p2_value:Point=None)->None:
        pass
    
    @property
    def y_intersection(self)->float:
        return self._y_intersection
    
    @y_intersection.setter
    def y_intersection(self,value)->None:
        self._y_intersection = value


    @property
    def p1(self):
        return self._p1
    
    @p1.setter
    def p1(self,p1_value):
        print(f"[info] {p1_value} is a point of the line")
        self._p1 = p1_value
    
    @property
    def p2(self):
        return self._p2
    
    @p2.setter
    def p2(self,p2_value):
        print(f"[info] {p2_value} is a point of the line")
        self._p2 = p2_value

    
