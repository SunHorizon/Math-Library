#include "Vector4.h"



Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}
Vector4::Vector4(float x_, float y_, float z_, float w_) {
	x = x_;
	y = y_;
	z = z_;
	w = w_;
}
Vector4::Vector4(Vector3 Vec, float w_) {
	x = Vec.x;
	y = Vec.y;
	z = Vec.y;
	w = w_;
}

float Vector4::Mag() {

	return sqrt((x*x) + (y*y) + (z*z) + (w*w));
}

Vector4 Vector4::operator * (const float s) const {

	Vector4 newVec;
	newVec.x = x * s;
	newVec.y = y * s;
	newVec.z = z * s;
	newVec.w = w * s;

	return newVec;

}
Vector4 Vector4::operator + (const Vector4& v) const {

	Vector4 newVec;
	newVec.x = x + v.x;
	newVec.y = y + v.y;
	newVec.z = z + v.z;
	newVec.w = w + v.w;
	return newVec;
}

Vector4 Vector4::operator / (const float s) const {

	Vector4 newVec;
	newVec.x = x / s;
	newVec.y = y / s;
	newVec.z = z / s;
	newVec.w = w / s;

	return newVec;

}
void Vector4::Normalize() {

	x = x / this->Mag();
	y = y / this->Mag();
	z = z / this->Mag();
	w = w / this->Mag();

}
float Vector4::Dot(Vector4 otherVec) {

	return (x * otherVec.x) + (y * otherVec.y) + (z * otherVec.z) + (w * otherVec.w);
}
Vector4::~Vector4()
{
}
