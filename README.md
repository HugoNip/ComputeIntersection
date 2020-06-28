# 1 Introduction


Distance computations are fundamental in computational geometry, 
and there are well-known formulas for them. 
Nevertheless, due to differences in object representations, 
there are alternative solutions to choose from. 
We will give some of these and indicate the situations they apply to.

We present several basic methods for representing planes in 3D space, 
and how to compute the distance of a point to a plane.

The intersection of geometric primitives is a fundamental construct in many computer graphics 
and modeling applications. Here we look at the algorithms for the simplest 2D and 3D linear primitives: 
lines, segments and planes.



# 2 Distance of a point and a line
## 2.1 2D space, find the closest point to a line
![Pic_segment.gif](https://github.com/HugoNip/GraphBasic/blob/master/figure/Pic_segment.gif)

## 2.2 2D space, calculate the distance
![Pic_dparametric.gif](https://github.com/HugoNip/GraphBasic/blob/master/figure/Pic_dparametric.gif)

# 3 Distance of a point and a plane
## 3.1 3D space, calculate the distance
![Pic_dplane.gif](https://github.com/HugoNip/GraphBasic/blob/master/figure/Pic_dplane.gif)

# 4 Intersections of lines and planes
## 4.1 2D space, intersection of two segments
![Pic_line-line.gif](https://github.com/HugoNip/GraphBasic/blob/master/figure/Pic_line-line.gif)

## 4.2 3D space, intersection of a segment and a plane
![Pic_line-plane.gif](https://github.com/HugoNip/GraphBasic/blob/master/figure/Pic_line-plane.gif)

## 4.3 3D space, intersection of two planes
![Pic_2-planes.gif](https://github.com/HugoNip/GraphBasic/blob/master/figure/Pic_2-planes.gif)

# 5 Compile this Project
```
mkdir build
cd build
cmake ..
make 
```

# 6 Run
```
./build/point2Line
./build/point2Plane
./build/geometryIntersection
```

# Reference
[Lines and distance of a point and a line](http://geomalgorithms.com/a02-_lines.html#closest2D_Point_to_Line())  
[Planes and distance of a point and a line](http://geomalgorithms.com/a04-_planes.html)  
[Intersections of lines and planes](http://geomalgorithms.com/a05-_intersect-1.html)  
[Operator Overloading for 3D Vector](https://www.cs.uaf.edu/2010/spring/cs202/lecture/02_18_operators.html)  
