#include "Quaternion.h"
#include <cmath>


Quaternion::Quaternion()
{
	quaternion.x = 0;
	quaternion.y = 0;
	quaternion.z = 0;
	quaternion.w = 1;
}


Quaternion::Quaternion(float x , float y, float z, float w) {

	quaternion.x = x;
	quaternion.y = y;
	quaternion.z = z;
	quaternion.w = w;
}

Quaternion::Quaternion(Vector3 axis, float angleInDegrees) {

	angleInDegrees *= DEGREES_TO_RADIANS;
	quaternion.x = axis.x * sin(angleInDegrees / 2);
	quaternion.y = axis.y * sin(angleInDegrees / 2);
	quaternion.z = axis.z * sin(angleInDegrees / 2);
	quaternion.w = cos(angleInDegrees / 2);

}
void Quaternion::Set(float _x, float _y, float _z, float _w) {
	quaternion.x = _x;
	quaternion.y = _y;
	quaternion.z = _z;
	quaternion.w = _w;
}
Quaternion Quaternion::operator * (const Quaternion& otherQuat) const {

	Vector3 q1(quaternion.x, quaternion.y, quaternion.z);
	Vector3 q2(otherQuat.quaternion.x, otherQuat.quaternion.y, otherQuat.quaternion.z);
	float w1 = quaternion.w;
	float w2 = otherQuat.quaternion.w;	

	float S = (w1 * w2) - q1.Dot(q2);
	Vector3 V = (q2 * w1) + (q1 * w2) + q1.Cross(q2);
	Quaternion newQuaternion(V.x, V.y, V.z, S);

	return newQuaternion;
}

float Quaternion::Mag() {

	Vector3 v(quaternion.x, quaternion.y, quaternion.z);
	float mag = sqrt((quaternion.w * quaternion.w) + v.Mag() * v.Mag());

	return mag;
}

void Quaternion::Normalize() {

	float mag = this->Mag();
	quaternion = quaternion / mag;
}

void Quaternion::Conjugate() {
	quaternion.x = quaternion.x * -1;
	quaternion.y = quaternion.y * -1;
	quaternion.z = quaternion.z * -1;
}

void Quaternion::Inverse() {

	this->Conjugate();
	quaternion.x = quaternion.x / quaternion.Mag();
	quaternion.y = quaternion.y / quaternion.Mag();
	quaternion.z = quaternion.z / quaternion.Mag();
}

Vector3 Quaternion::Rotate(Vector3 vec) {

	Quaternion q = Quaternion(vec.x, vec.y, vec.z, 0);
	Quaternion qq = Quaternion(quaternion.x , quaternion.y, quaternion.z , quaternion.w);
	Quaternion qqInverse = qq;
	qqInverse.Inverse();

	Quaternion result = qq * (q * qqInverse);

	return Vector3(result.quaternion.x, result.quaternion.y, result.quaternion.z);

}
// getting the slerp
Quaternion Quaternion::Slerp(Quaternion otherQuat, float t) {
	
	Quaternion q1(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	q1.Normalize();
	otherQuat.Normalize();
	Quaternion result;
	float theta = acos(q1.quaternion.Dot(otherQuat.quaternion));

	if (theta < VERY_SMALL) {
		Vector4 r = ((quaternion * (1 - t)) + (otherQuat.quaternion * t));
		result.Normalize();

		result.Set(r.x, r.y, r.z, r.w);
	}
	else{	
		
		Vector4 r = (q1.quaternion * (sin(theta * (1 - t)) / sin(theta))) + (otherQuat.quaternion * (sin(t * theta)/ sin(theta)));
		result.Set(r.x, r.y, r.z, r.w);
	}
	return result;
}


Mat3 Quaternion::ConvertToMatrix() {

	float m1 = 1 - ((2* (quaternion.y * quaternion.y)) - (2 * (quaternion.z * quaternion.z)));
	float m2 = ((2 * (quaternion.x * quaternion.y)) + (2 * (quaternion.w * quaternion.z)));
	float m3 = ((2 * (quaternion.x * quaternion.z)) - (2 * (quaternion.w * quaternion.y)));

	float m4 = ((2 * (quaternion.x * quaternion.y)) - (2 * (quaternion.w * quaternion.z)));
	float m5 = 1 - ((2 * (quaternion.x * quaternion.x)) - (2 * (quaternion.z * quaternion.z)));
	float m6 = ((2 * (quaternion.y * quaternion.z)) + (2 * (quaternion.w * quaternion.x)));

	float m7 = ((2 * (quaternion.x * quaternion.z)) + (2 * (quaternion.w * quaternion.y)));
	float m8 = ((2 * (quaternion.y * quaternion.z)) - (2 * (quaternion.w * quaternion.x)));
	float m9 = 1 - ((2 * (quaternion.x * quaternion.x)) - (2 * (quaternion.y * quaternion.y)));
	
	return Mat3(m1, m2, m3, m4, m5, m6, m7, m8, m9);
}


Quaternion::~Quaternion()
{

}
