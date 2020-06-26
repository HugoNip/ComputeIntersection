//
// Created by nipnie on 6/25/20.
//

#ifndef PLANEINTERSECTION_INTERSECTIONFUNS_H
#define PLANEINTERSECTION_INTERSECTIONFUNS_H

#include <iostream>
#include <vector>

// Assume that classes are already given for the objects:
//    Point and Vector with
//        coordinates {float x, y, z;}
//        operators for:
//            == to test  equality
//            != to test  inequality
//            Point   = Point ± Vector
//            Vector =  Point - Point
//            Vector =  Scalar * Vector    (scalar product)
//            Vector =  Vector * Vector    (3D cross product)
//    Line and Ray and Segment with defining  points {Point P0, P1;}
//        (a Line is infinite, Rays and  Segments start at P0)
//        (a Ray extends beyond P1, but a  Segment ends at P1)
//    Plane with a point and a normal {Point V0; Vector  n;}
//===================================================================


#define SMALL_NUM   0.00000001 // anything that avoids division overflow
// dot product (3D) which allows vector operations in arguments
#define dot(u,v)   ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z)
#define perp(u,v)  ((u).x * (v).y - (u).y * (v).x)  // perp product  (2D)

struct Vector{
    float x, y, z;
};

struct Point{
    float x, y, z;
};

struct Line{
    Point P0, P1;
};

struct Ray{
    Point P0, P1;
};

struct Segment{
    Point P0, P1;
};

struct Plane{
    Point V0;
    Vector n;
};

// intersect2D_2Segments(): find the 2D intersection of 2 finite segments
//    Input:  two finite segments S1 and S2
//    Output: *I0 = intersect point (when it exists)
//            *I1 =  endpoint of intersect segment [I0,I1] (when it exists)
//    Return: 0=disjoint (no intersect)
//            1=intersect  in unique point I0
//            2=overlap  in segment from I0 to I1
int intersect2D_2Segments( Segment S1, Segment S2, Point* I0, Point* I1 );


// inSegment(): determine if a point is inside a segment
//    Input:  a point P, and a collinear segment S
//    Return: 1 = P is inside S
//            0 = P is  not inside S
int inSegment( Point P, Segment S);


// intersect3D_SegmentPlane(): find the 3D intersection of a segment and a plane
//    Input:  S = a segment, and Pn = a plane = {Point V0;  Vector n;}
//    Output: *I0 = the intersect point (when it exists)
//    Return: 0 = disjoint (no intersection)
//            1 =  intersection in the unique point *I0
//            2 = the  segment lies in the plane
int intersect3D_SegmentPlane( Segment S, Plane Pn, Point* I );


// intersect3D_2Planes(): find the 3D intersection of two planes
//    Input:  two planes Pn1 and Pn2
//    Output: *L = the intersection line (when it exists)
//    Return: 0 = disjoint (no intersection)
//            1 = the two  planes coincide
//            2 =  intersection in the unique line *L
int intersect3D_2Planes( Plane Pn1, Plane Pn2, Line* L );


#endif //PLANEINTERSECTION_INTERSECTIONFUNS_H
