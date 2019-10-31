#ifndef Vector3_H
#define Vector3_H


namespace MATH {

	#define  VERY_SMALL 1.0e-7f
	#define  DEGREES_TO_RADIANS (3.141/180)
	class Vector3
	{
	private:
		
	public:
		float x, y, z;
		Vector3(float x_, float y_, float z_);
		Vector3();
		void Add(Vector3 otherVec);
		Vector3 operator + (const Vector3& v) const;
		Vector3 operator += (const Vector3& v) const;
		void Subtract(Vector3 otherVec);
		Vector3 operator - (const Vector3& v) const;
		Vector3 operator -= (const Vector3& v) const;
		void ScalarMultiplication(float scalar);
		Vector3 operator * (const float s) const;
		Vector3 operator *= (const float s) const;
		float Mag();
		void Normalize();
		float Dot(Vector3 otherVec);
		Vector3 Cross(Vector3 otherVec);
		~Vector3();


	};
}
#endif
