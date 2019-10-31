#ifndef Vector4_H
#define Vector4_H
#include "Vector3.h"
#include <math.h>

using namespace MATH;

	class Vector4: public Vector3
	{
	public:
		float w;
		Vector4();
		Vector4(float x_, float y_, float z_, float w_);
		Vector4(Vector3 Vec, float w_);
		~Vector4();
		Vector4 operator * (const float s) const;
		Vector4 operator + (const Vector4& v) const;
		Vector4 operator / (const float s) const;
		void Normalize();
		float Dot(Vector4 otherVec);
		float Mag();

	};
#endif
