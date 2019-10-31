#ifndef Plane_H
#define Plane_H
#include "Vector4.h"
#include "Ray.h"
#include <math.h>


using namespace MATH;
	class Plane
	{
	public:
		Vector4 plane;
		Vector3 v0,v1,v2;
		Plane(float x_, float y_, float z_, float d_);
		Plane(const Vector3 v0, const Vector3 v1, const Vector3 v2);
		Vector3 intersectionPoint(Ray ray);
		~Plane();
	};

#endif
