//
// Created by nipnie on 6/26/20.
//
#include "point2Line.h"

int closest2D_Point_to_Line( Point P[], int n, Line L)
{
    // Get coefficients of the implicit line equation.
    // Do NOT normalize since scaling by a constant
    // is irrelevant for just comparing distances.
    float a = L.P0.y - L.P1.y;
    float b = L.P1.x - L.P0.x;
    float c = L.P0.x * L.P1.y - L.P1.x * L.P0.y;

    // initialize min index and distance to P[0]
    int mi = 0;
    float min = a * P[0].x + b * P[0].y + c;
    if (min < 0) min = -min;     // absolute value

    // loop through Point array testing for min distance to L
    for (int i = 1; i < n; i++) {
        // just use dist squared (sqrt not  needed for comparison)
        float dist = a * P[i].x + b * P[i].y  + c;
        if (dist < 0) dist = -dist;    // absolute value
        if (dist < min) {      // this point is closer
            mi = i;              // so have a new minimum
            min = dist;
        }
    }

    return mi; // the index of the closest Point P[mi]
}

float dist_Point_to_Line( Point P, Line L)
{
    Vector v = L.P1 - L.P0;
    Vector w = P - L.P0;

    double c1 = dot(w,v);
    double c2 = dot(v,v);
    double b = c1 / c2;

    Point Pb = L.P0 + b * v;
    return d(P, Pb);
}

float dist_Point_to_Segment( Point P, Segment S)
{
    Vector v = S.P1 - S.P0;
    Vector w = P - S.P0;

    double c1 = dot(w,v);
    if ( c1 <= 0 ) // before P0
        return d(P, S.P0);

    double c2 = dot(v,v);
    if ( c2 <= c1 ) // after P1
        return d(P, S.P1);

    double b = c1 / c2;
    Point Pb = S.P0 + b * v;
    return d(P, Pb);
}

int main (int argc, char ** argv) {

    /**
     * find the closest point to a line
     */
    Line line = {{1, 2, 0}, {7, 13, 0}};

    Point points[] = {{3, 20, 0},
                      {-2, 0, 0},
                      {4, 28, 0}};

    int n = sizeof( points ) / sizeof( points[0] ); // size of array
    int id;

    std::cout << "There are " << n << " points." << std::endl;

    id = closest2D_Point_to_Line(points, n, line);

    std::cout << "The closest Point is id: " << id << "th, " <<
                                         "[" << points[id].x << ", "
                                             << points[id].y << ", "
                                             << points[id].z << "]" << std::endl;

    /**
     * calculate the distance
     */
    // infinite line
    float dist1 = dist_Point_to_Line(points[id], line);
    std::cout << "The closest distance between point and line is " << std::endl;
    std::cout << "[method 1]: " << dist1 << ";" << std::endl;

    // sgement
    Segment seg = {line.P0, line.P1};
    float dist2 = dist_Point_to_Segment(points[id], seg);
    std::cout << "[method 2]: " << dist2 << ";" << std::endl;

    return 0;

}

