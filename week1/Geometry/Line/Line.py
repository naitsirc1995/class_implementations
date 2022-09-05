from __future__ import annotations
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
        
        if p1 and not p2 and slope and not y_intersection:
            raise ValueError("[error] y_intersection needed to make a line")
        
        if (p1 is not None and  p2 is None) and (slope is None and y_intersection is None):            
            raise ValueError("[error] a second point or a slope is needed to form a line")

        if (p1 is None and p2 is not None) and (slope is None and y_intersection is None):
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
        elif self.is_vertical():
            return float('inf')
        elif self.is_horizontal():
            return 0
        elif self.p1 and self.p2:
            return (self.p2.y_coordinate - self.p1.y_coordinate)/(self.p2.x_coordinate - self.p1.x_coordinate)
        
        elif (self.p1 or self.p2) and self.y_intersection:            
            point:Point = self.point
            if point.x_coordinate == 0:
                raise ValueError("[error] provided point can't have x-coordinate=0")
            return (point.y_coordinate - self.y_intersection)/point.x_coordinate

        else:
            raise ValueError("[error] slope can not be determined")
    
    @slope.setter
    def slope(self,slope_value:float)->None:
        if self._slope:
            raise ValueError("Slope was already provided")        
        elif (slope_value == float('inf')) and not (self.p1 or self.p2):
            raise ValueError("With an infinite slope at least one point must be provided")
        elif (slope_value == 0) and not (self.p1 or self.p2):
            raise ValueError("With a zero slope at least one point must be provided")
        else:
            #print(f"[info] slope was set with value {slope_value}")
            self._slope = slope_value
    


    @property
    def y_intersection(self)->float:
        if self._y_intersection:
            return self._y_intersection
        elif (self.is_horizontal()):
            return self.point.y_coordinate
        elif (self.is_vertical()):
            raise ValueError("[error] vertical line has no y-intersection")
        elif (self.p1 or self.p2) and self.slope:
            point:Point = self.point
            return point.y_coordinate - self.slope*point.x_coordinate
        
        
        else:
            raise ValueError("[error] y-intersection can't be computed")
    
    @y_intersection.setter
    def y_intersection(self,y_intersection_value)->None:
        if self._y_intersection:            
            raise ValueError("y-intersection was already provided")
        else:
            #print(f"[info] y-intersection was set with value {y_intersection_value}")
            self._y_intersection = y_intersection_value


    @property
    def p1(self)->Point:
        return self._p1
    
    @p1.setter
    def p1(self,p1_value)->None:
        if self._p1:            
            raise ValueError("p1 point was already provided")
        else:
            #print(f"[info] {p1_value} is a point of the line")
            self._p1 = p1_value
    
    
    @property
    def p2(self)->Point:
        return self._p2
    
    @p2.setter
    def p2(self,p2_value)->None:
        if self._p2:
            raise ValueError("p2 point was already provided")
        else:
            #print(f"[info] {p2_value} is a point of the line")
            self._p2 = p2_value

    @property
    def point(self)->Point:
        if self.p1 or self.p2:
            point:Point = list(filter(lambda x : x != None,[self.p1,self.p2]))[0]
            return point
        else:
            raise ValueError("There must be at least one point")

    def is_vertical(self)->bool:
        if self.p1 is not None and self.p2 is not None:
            return (self.p1.x_coordinate == self.p2.x_coordinate)
        elif self.slope is not None and (self.p1 is None or self.p2 is None):
            return (self.slope == float('inf'))
        else:            
            raise ValueError("[error] can not be determined verticality")
    
    def is_horizontal(self)->bool:        
        if self.p1 is not None and self.p2 is not None:
            return (self.p1.y_coordinate == self.p2.y_coordinate)
        elif self.slope is not None and (self.p1 is None or self.p2 is None):
            return (self.slope == 0)
        else:
            raise ValueError("[error] can not be determined verticality")
    
    def belongs(self,point:Point)->bool:
        if self.is_vertical():            
            return (self.point.x_coordinate == point.x_coordinate)
        
        elif self.is_horizontal():
            return (self.point.y_coordinate == point.y_coordinate)
        
        else:
            return point.y_coordinate == point.x_coordinate*self.slope + self.y_intersection
    
    def is_between_points(self,line_point_1:Point,line_point_2:Point,point:Point)->bool:
        if not self.belongs(line_point_1) or not self.belongs(line_point_2):
            ValueError("[error] one of the points given does not belong to the line")
        if self.belongs(line_point_1) and self.belongs(line_point_2) and self.belongs(point):
            #print(f"[info] points {line_point_1} and {line_point_2} were given")
            #print(f"[info] asserting if {point} is in between points given")
            if self.is_vertical():                
                min_y = min(line_point_1.y_coordinate,line_point_2.y_coordinate)
                max_y = max(line_point_1.y_coordinate,line_point_2.y_coordinate) 
                return (min_y < point.y_coordinate) and (max_y > point.y_coordinate)
            elif self.is_horizontal():
                
                min_x = min(line_point_1.x_coordinate,line_point_2.y_coordinate)
                max_x = max(line_point_1.x_coordinate,line_point_2.y_coordinate)
                return (min_x < point.x_coordinate) and (max_x > point.x_coordinate)
            else:
                min_y = min(line_point_1.y_coordinate,line_point_2.y_coordinate)
                max_y = max(line_point_1.y_coordinate,line_point_2.y_coordinate)
                min_x = min(line_point_1.x_coordinate,line_point_2.y_coordinate)
                max_x = max(line_point_1.x_coordinate,line_point_2.y_coordinate)
                return (min_y < point.y_coordinate) and (max_y > point.y_coordinate) and (min_y < point.y_coordinate) and (max_y > point.y_coordinate)

        else:
            #print(f"[info] point {point} is not part of the line")
            return False
                        
            
    def is_line_intersection_between_points(self,line:Line, line_point_1:Point,line_point_2:Point)->bool:
        if self.is_vertical():                
            return self.is_between_points(line_point_1=line_point_1,line_point_2=line_point_2,point=Point(line_point_1.x_coordinate,line.point.y_coordinate))                
        elif self.is_horizontal():
            return line.point.y_coordinate == line_point_1.y_coordinate
        else:
            y_intersection = line.point.y_coordinate
            x_intersection = (y_intersection - self.y_intersection)/self.slope
            return self.is_between_points(line_point_1=line_point_1,line_point_2=line_point_2,point=Point(x_intersection,y_intersection))        
            
    def get_x_intersection(self,line:Line, line_point_1:Point,line_point_2:Point) -> float:
        intersection_bool = self.is_line_intersection_between_points(line,line_point_1,line_point_2)
        if intersection_bool and self.is_vertical():
            return line_point_1.x_coordinate
        elif intersection_bool:
            return (line.point.y_coordinate - self.y_intersection)/self.slope
        elif self.is_horizontal():
            raise ValueError("[error] can not handle horizontal lines")
        else:
            raise ValueError("[error] there is not intersection between lines")

    def evaluate_x_coordinate(self,x_value)->float:
        if self.is_vertical():
            raise ValueError(f"[error] can not evaluate {x_value} in horizontal line")
        elif self.is_horizontal():
            return self.point.y_coordinate
        else:
            return x_value*self.slope + self.y_intersection
