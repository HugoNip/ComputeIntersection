//
// Created by nipnie on 6/27/20.
//

#include "point2Plane.h"

float dist_Point_to_Plane( Point P, Plane PL, Point B)
{
    float sb, sn, sd;

    sn = -dot( PL.n, (P - PL.V0)); // n * (P - V0)
    sd = dot(PL.n, PL.n); // |n|
    sb = sn / sd; // scale for base point
    B = P + sb * PL.n;

    return d(P, B);
}

int main (int argc, char ** argv) {

    // define a point
    Point p1 = {6, 8, 3};
    Point basePoint1;
    Plane plane1 = {{1, 2, 3}, {7, 9, 4}};

    float dist1 = dist_Point_to_Plane(p1, plane1, basePoint1);

    std::cout << "The closed distance is " << dist1
              << " with base point " << "["
              << basePoint1.x << ", "
              << basePoint1.y << ", "
              << basePoint1.z << "]." << std::endl;

    return 0;
}