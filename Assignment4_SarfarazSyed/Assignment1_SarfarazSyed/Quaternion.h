#ifndef Quaternion_H
#define Quaternion_H
#include "Vector4.h"
#include "Mat4.h"
class Quaternion
{
public:
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion(Vector3 axis, float angleInDegrees);
	Vector4 quaternion;
	Quaternion operator * (const Quaternion& otherQuat) const;
	float Mag();
	void Normalize();
	void Conjugate();
	void Inverse();
	Vector3 Rotate(Vector3 vec);
	void Set(float _x, float _y, float _z, float _w);
	Quaternion Slerp(Quaternion otherQuat, float t);
	Mat3 ConvertToMatrix();

	~Quaternion();
};
#endif
