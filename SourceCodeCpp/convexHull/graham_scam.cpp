#include "graham_scam.h"

Point pivot;

int ccw(Point a, Point b, Point c){
    float area = (b.x_coordinate - a.x_coordinate)*(c.y_coordinate-a.y_coordinate) - (b.y_coordinate - a.y_coordinate)*(c.x_coordinate - a.x_coordinate);
    if (area > 0 )
        return -1;
    else if (area < 0)
        return 1;
    return 0;
};

float sqrDist(Point a, Point b){
    float dx = a.x_coordinate - b.x_coordinate, dy = a.y_coordinate - b.y_coordinate;
    return dx*dx + dy*dy;
};

bool POLAR_ORDER(Point a, Point b){
    int order = ccw(pivot,a,b);
    if (order == 0)
        return sqrDist(pivot,a) < sqrDist(pivot,b);
    return (order == -1);
};

Polygon* grahamScan(Point* points, int N){
    std::stack<Point> hull;

    if (N<3) return NULL;

    int leastY = 0;
    for (int i = 1;i<N;i++)
        if (points[i] < points[leastY])
            leastY = i;
    
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    pivot = points[0];
    std::sort(points+1,points+N,POLAR_ORDER);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N;i++){
        Point top = hull.top();
        hull.pop();
        while (ccw(hull.top(),top,points[i]) != -1){
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }

    int numberPoints = hull.size();
    Point* polygonPoints = new Point[numberPoints];
    int i = 0;
    while (!hull.empty()){
        Point p = hull.top();
        polygonPoints[i] = p;
        hull.pop();
        i++;
    }

    return new Polygon(polygonPoints,numberPoints);
};
