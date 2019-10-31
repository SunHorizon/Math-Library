#include "Plane.h"

#include <iostream>


Plane::Plane(float x_, float y_, float z_, float d_)
{
	plane.x = x_;
	plane.y = y_;
	plane.z = z_;
	plane.w = d_;
}

Plane::Plane(const Vector3 v0_, const Vector3 v1_, const Vector3 v2_)
{
	Vector3 tempPointA = v1 - v0;
	Vector3 tempPointB = v2 - v1;
	Vector3 Cross = tempPointA.Cross(tempPointB);
	Cross.Normalize();
	float d = Cross.Dot(v1);
	Plane(Cross.x , Cross.y , Cross.z , d);
}

Vector3 Plane::intersectionPoint(Ray ray) {

	
	Vector3 normalP;
	Vector3 pos;
	Ray line = ray;
	normalP.x = plane.x;
	normalP.y = plane.y;
	normalP.z = plane.z;

	// check if there is intersection
	float lineC = normalP.Dot(line.dir);

	if (abs(lineC) <  VERY_SMALL ) { //N.V==0

		Vector4 s(line.start.x, line.start.y, line.start.z, 1);// homogenous coordinates
		if (abs(this->plane.Dot(s)) < VERY_SMALL)// L.S , where is is homogenous coordinates
		{
			std::cout << "Line is on the plane"<<std::endl;
		}
		else 
		{
			std::cout << "no intersection the lane is // to plane" << std::endl;
		}
		return Vector3(0.0f, 0.0f, 0.0f);
	}else {
		//calculate t
		// plug in for t , use teh equation of the line

		// check if line is on the point
		float checkIn = normalP.Dot(line.start);
		checkIn = -(checkIn + plane.w);

		// get the t
		float t = checkIn / lineC;

		// check the current pos
		pos = (line.currentPosition(t));
		return pos;
	}
}

Plane::~Plane()
{

}
