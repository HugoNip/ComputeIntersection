//
// Created by nipnie on 6/27/20.
//

#include "point2Plane.h"

float dist_Point_to_Plane( Point P, Plane PL, Point* B)
{
    float    sb, sn, sd;

    sn = -dot( PL.n, (P - PL.V0));
    sd = dot(PL.n, PL.n);
    sb = sn / sd;

    *B = P + sb * PL.n;
    return d(P, *B);
}

int main (int argc, char ** argv) {

    return 0;
}