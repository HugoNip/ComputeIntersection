//
// Created by nipnie on 6/27/20.
//
#ifndef POINT2PLANE_H
#define POINT2PLANE_H

#include "commonInclulde.h"

// dist_Point_to_Plane(): get distance (and perp base) from a point to a plane
//    Input:  P  = a 3D point
//            PL = a  plane with point V0 and normal n
//    Output: *B = base point on PL of perpendicular from P
//    Return: the distance from P to the plane PL
float dist_Point_to_Plane( Point P, Plane PL, Point B);

#endif //POINT2PLANE_H
