//
// Created by nipnie on 6/27/20.
//

#ifndef COMMONINCLULDE_H
#define COMMONINCLULDE_H

#include <iostream>
#include <cmath>

// dot product (3D) which allows vector operations in arguments
#define dot(u,v) ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z)
#define norm(v) sqrt(dot(v,v))     // norm = length of  vector
#define d(u,v) norm(u-v)          // distance = norm of difference
#define perp(u,v) ((u).x * (v).y - (u).y * (v).x)  // perp product  (2D)

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

struct Vector{
    float x, y, z;
};

struct Point{
    float x, y, z;
};

Vector operator - (const Point &p1, const Point &p2) {
    Vector v3;
    v3.x = p1.x - p2.x;
    v3.y = p1.y - p2.y;
    v3.z = p1.z - p2.z;
    return v3;
}

bool operator != (const Point &p1, const Point &p2) {
    bool b = false;
    if (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z)
        b = true;
    return b;
}

// scalar product
Vector operator * (float scale, const Vector &v) {
    Vector v3;
    v3.x = scale * v.x;
    v3.y = scale * v.y;
    v3.z = scale * v.z;
    return v3;
}

// 3D cross product
Vector operator * (const Vector &v1, const Vector &v2) {
    Vector v3;
    v3.x = v1.y * v2.z - v1.z * v2.y;
    v3.y = v1.z * v2.x - v1.x * v2.z;
    v3.z = v1.x * v2.y - v1.y * v2.x;
    return v3;
}

Point operator + (const Point &p1, const Vector &p2) {
    Point p3;
    p3.x = p1.x - p2.x;
    p3.y = p1.y - p2.y;
    p3.z = p1.z - p2.z;
    return p3;
}

struct Line{
    Point P0; // start point
    Point P1; // end point
};

struct Segment{
    Point P0; // start point
    Point P1; // end point
};

struct Plane{
    Point V0;
    Vector n; // normal
};

#endif //COMMONINCLULDE_H

/** A 3D vector: a direction or location in 3D space.
class vec3 {
public:
	float x,y,z;

	vec3(void) {}//Default consructor
	/// Simple 1-value constructors
	vec3(int init) {x=y=z=(float)init;}
	vec3(float init) {x=y=z=(float)init;}
	vec3(double init) {x=y=z=(float)init;}

	/// 3-value constructor
	vec3(const float Nx,const float Ny,const float Nz) {x=Nx;y=Ny;z=Nz;}
	/// float array constructor
	vec3(const float *arr) {x=arr[0];y=arr[1];z=arr[2];}

	// Copy constructor & assignment operator are by default

	/// This lets you typecast a vector to a float array
	operator float *() {return (float *)&x;}
	operator const float *() const {return (const float *)&x;}

//Basic mathematical operators
	int operator==(const vec3 &b) const {return (x==b.x)&&(y==b.y)&&(z==b.z);}
	int operator!=(const vec3 &b) const {return (x!=b.x)||(y!=b.y)||(z!=b.z);}
	vec3 operator+(const vec3 &b) const {return vec3(x+b.x,y+b.y,z+b.z);}
	vec3 operator-(const vec3 &b) const {return vec3(x-b.x,y-b.y,z-b.z);}
	vec3 operator*(const float scale) const
		{return vec3(x*scale,y*scale,z*scale);}
	vec3 operator/(const float &div) const
		{float scale=1.0/div;return vec3(x*scale,y*scale,z*scale);}
	vec3 operator-(void) const {return vec3(-x,-y,-z);}
	void operator+=(const vec3 &b) {x+=b.x;y+=b.y;z+=b.z;}
	void operator-=(const vec3 &b) {x-=b.x;y-=b.y;z-=b.z;}
	void operator*=(const float scale) {x*=scale;y*=scale;z*=scale;}
	void operator/=(const float div) {float scale=1.0/div;x*=scale;y*=scale;z*=scale;}

//Vector-specific 3D operations
	/// Return the square of the magnitude of this vector
	float magSqr(void) const {return x*x+y*y+z*z;}
	/// Return the magnitude (length) of this vector
	float mag(void) const {return sqrt(magSqr());}

	/// Return the square of the distance to the vector b
	float distSqr(const vec3 &b) const
		{return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)+(z-b.z)*(z-b.z);}
	/// Return the distance to the vector b
	float dist(const vec3 &b) const {return sqrt(distSqr(b));}

	/// Return the dot product of this vector and b
	float dot(const vec3 &b) const {return x*b.x+y*b.y+z*b.z;}
	/// Return the cosine of the angle between this vector and b
	float cosAng(const vec3 &b) const {return dot(b)/(mag()*b.mag());}

	/// Return the "direction" (unit vector) of this vector
	vec3 dir(void) const {return (*this)/mag();}
	/// Return the right-handed cross product of this vector and b
	vec3 cross(const vec3 &b) const {
		return vec3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
	}
	/// Make this vector have unit length
	void normalize(void) { *this=this->dir();}

	/// Return the largest coordinate in this vector
	float max(void) const {
		float big=x;
		if (big<y) big=y;
		if (big<z) big=z;
		return big;
	}
	/// Make each of this vector's coordinates at least as big
	///  as the given vector's coordinates.
	void enlarge(const vec3 &by) {
		if (x<by.x) x=by.x;
		if (y<by.y) y=by.y;
		if (z<by.z) z=by.z;
	}
};

//// Utility wrapper functions
inline float dist(const vec3 &a,const vec3 &b)
{ return a.dist(b); }

inline float dot(const vec3 &a,const vec3 &b)
{ return a.dot(b); }

inline vec3 cross(const vec3 &a,const vec3 &b)
{ return a.cross(b); }

/// Allows "3.0*vec" to compile:
inline vec3 operator*(float scale,const vec3 &v)
{return vec3(v.x*scale,v.y*scale,v.z*scale);}

/// Nice vector print function
inline ostream &operator<<(ostream &s,const vec3 &v) {
    s<<"("<<v.x<<", "<<v.y<<", "<<v.z<<")";
    return s;
}

// Tiny example of using vectors
int foo(void) {
    vec3 C(100.0,110.0,120.0), D(0.1,0.4,0.3); // ray start and direction
    for (float t=0.5;t<4.0;t+=1.0) {
        vec3 P=C+t*D; // move down ray by t units
        cout<<"t="<<t<<" and P="<<P<<"\n";
    }
    return 0;
}
*/