#ifndef Mat4_H
#define Mat4_H
#include "Vector3.h"
#include "Vector4.h"

#define  PI 3.14

using namespace MATH;

class Mat3
{
public:

	float m[9];
	Mat3();
	Mat3(float x0, float x1, float x2,
		float y0, float y1, float y2,
		float z0, float z1, float z2);
	void SetIdentity();
	void SetMatrix(float x0, float x1, float x2,
		float y0, float y1, float y2,
		float z0, float z1, float z2);
	void Print() const;
};

class Mat4
{
public:
	Mat4();
	Mat4(float x0, float x1, float x2, float x3,
		float y0, float y1, float y2, float y3,
		float z0, float z1, float z2, float z3,
		float w0, float w1, float w2, float w3);
	~Mat4();
	float m[16];
	void SetIdentity();
	void RotateX(float angleInDegrees);
	void RotateY(float angleInDegrees);
	void RotateZ(float angleInDegrees);
	void Scale(float x, float y, float z);
	void Translate(Vector3 translation);
	void Transpose();
	void Print() const;
	void SetMatrix(float x0, float x1, float x2, float x3,
		float y0, float y1, float y2, float y3,
		float z0, float z1, float z2, float z3,
		float w0, float w1, float w2, float w3);

	float Det();
	float SecondOrder(float x1, float y1,
					  float x2,  float y2);

	float ThirdOrder(float x1, float y1, float z1,
					 float x2, float y2, float z2,
					 float x3, float y3, float z3);

	void Inverse();
	Mat4 operator*(const Mat4& n) const;
	Vector3 operator*(const Vector4 vector) const;
};
#endif