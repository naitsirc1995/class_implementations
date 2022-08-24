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
            self.p1 = p1
            self.p2 = p2
            self.slope = slope
            self.y_intersection = y_intersection
        


    @property
    def slope(self)->float:
        if self._slope:
            return self._slope
        elif self.p1 and self.p2:
            return (self.p2.y_coordinate - self.p1.y_coordinate)/(self.p2.x_coordinate - self.p2.x_coordinate)
        
        elif (self.p1 or self.p2) and self.y_intersection:            
            point:Point = list(filter(lambda x : x != None,[self.p1,self.p2]))[0]
            if point.x_coordinate == 0:
                raise ValueError("[error] provided point can't have x-coordinate=0")
            return (point.y_coordinate - self.y_intersection)/point.x_coordinate

        else:
            raise ValueError("[error] slope can not be determined")
    
    @slope.setter
    def slope(self,slope_value:float)->None:
        if not self._slope:
            raise ValueError("Slope was already provided")
        elif (slope_value == float('inf')) and not (self.p1 or self.p2):
            raise ValueError("With an infinite slope at least one point must be provided")
        elif (slope_value == 0) and not (self.p1 or self.p2):
            raise ValueError("With a zero slope at least one point must be provided")
        else:
            self._slope = slope_value
    


    @property
    def y_intersection(self)->float:
        if self._y_intersection:
            return self._y_intersection
        elif (self.p1 or self.p2) and self.slope:
            point:Point = list(filter(lambda x : x != None,[self.p1,self.p2]))[0]
            return point.y_coordinate - self.slope*point.x_coordinate
    
    @y_intersection.setter
    def y_intersection(self,y_intersection_value)->None:
        if not self._y_intersection:            
            raise ValueError("y-intersection was already provided")
        else:
            print(f"[info] {y_intersection_value} is set as y-intersection")
            self._y_intersection = y_intersection_value


    @property
    def p1(self)->Point:
        return self._p1
    
    @p1.setter
    def p1(self,p1_value)->None:
        if not self._p1:
            raise ValueError("p1 point was already provided")
        else:
            print(f"[info] {p1_value} is a point of the line")
            self._p1 = p1_value
    
    @property
    def p2(self)->Point:
        return self._p2
    
    @p2.setter
    def p2(self,p2_value)->None:
        if not self._p2:
            raise ValueError("p2 point was already provided")
        else:
            print(f"[info] {p2_value} is a point of the line")
            self._p2 = p2_value


    def is_vertical(self)->boolean:
        if self.p1 and self.p2:
            return (self.p1.x_coordinate == self.p2.x_coordinate)
        elif self.slope:
            return (self.slope == float('inf'))
        else:            
            raise ValueError("[error] can not be determined verticality")
    
    def is_horizontal(self)->boolean:        
        if self.p1 and self.p2:
            return (self.p1.y_coordinate == self.p2.y_coordinate)
        elif self.slope:
            return (self.slope == 0)
        else:
            raise ValueError("[error] can not be determined verticality")
    
    
