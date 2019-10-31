#include "Vector3.h"
#include <iostream>
#include <math.h>

using namespace MATH;

Vector3::Vector3()
{
	x = 0;
	y = 0; 
	z = 0;
}
Vector3::Vector3(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
}

void Vector3::Add(Vector3 otherVec) {

	x + otherVec.x;
	y + otherVec.y;
	z + otherVec.z;
}
 Vector3 Vector3::operator + (const Vector3& v) const {
	
	 Vector3 newVec;
	 newVec.x = x + v.x;
	 newVec.y = y + v.y;
	 newVec.z = z + v.z;

	 return newVec;
}
 Vector3 Vector3::operator += (const Vector3& v) const{

	 Vector3 newVec;
	 newVec.x += x + v.x;
	 newVec.y += y + v.y;
	 newVec.z += z + v.z;

	 return newVec;
 }

 void Vector3::Subtract(Vector3 otherVec) {
	
	  x - otherVec.x;
	  y - otherVec.y;
	  z - otherVec.z;
 }

 Vector3 Vector3::operator - (const Vector3& v) const {

	 Vector3 newVec;
	 newVec.x = x - v.x;
	 newVec.y = y - v.y;
	 newVec.z = z - v.z;

	 return newVec;
 }
 Vector3 Vector3::operator -= (const Vector3& v) const {

	 Vector3 newVec;
	 newVec.x -= x - v.x;
	 newVec.y -= y - v.y;
	 newVec.z -= z - v.z;

	 return newVec;
 }
 void Vector3::ScalarMultiplication(float scalar) {

	 x * scalar;
	 y * scalar;
	 z * scalar;
 }
 Vector3 Vector3::operator * (const float s) const {

	 Vector3 newVec;
	 newVec.x = x * s;
	 newVec.y = y * s;
	 newVec.z = z * s;

	 return newVec;
 }
 Vector3 Vector3::operator *= (const float s) const {

	 Vector3 newVec;
	 newVec.x *= x * s;
	 newVec.y *= y * s;
	 newVec.z *= z * s;

	 return newVec;
 }


 float Vector3::Mag() {

	 return sqrt((x*x) + (y*y) + (z*z));
 }
 void Vector3::Normalize() {
	  
	 x = x / Mag();
	 y = y / Mag();
	 z = z / Mag();


 }

 Vector3 Vector3::Cross(Vector3 otherVec) {
	 Vector3 crossVec; 
	 crossVec.x = (y * otherVec.z) - (z * otherVec.y);
	 crossVec.y = -((x * otherVec.z) - (z * otherVec.x));
	 crossVec.z = (x * otherVec.y) - (y * otherVec.x);

	 return crossVec;

 }
 float Vector3::Dot(Vector3 otherVec) {

	 return (x * otherVec.x) + (y * otherVec.y) + (z * otherVec.z);
 }

Vector3::~Vector3()
{
}
