//
// Created by nipnie on 6/26/20.
//

#ifndef POINT2LINE_H
#define POINT2LINE_H

#include "commonInclulde.h"

// closest2D_Point_to_Line(): find the closest 2D Point to a Line
//     Input:  an array P[] of n points, and a Line L
//     Return: the index i of the Point P[i] closest to L
int closest2D_Point_to_Line( Point P[], int n, Line L);


// dist_Point_to_Line(): get the distance of a point to a line
//     Input:  a Point P and a Line L (in any dimension)
//     Return: the shortest distance from P to L
float dist_Point_to_Line( Point P, Line L);


// dist_Point_to_Segment(): get the distance of a point to a segment
//     Input:  a Point P and a Segment S (in any dimension)
//     Return: the shortest distance from P to S
float dist_Point_to_Segment( Point P, Segment S);


#endif //PLANEINTERSECTION_POINT2LINE_H
