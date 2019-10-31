#include "Mat4.h"
#include <math.h>
#include <iostream>


Mat3::Mat3() {
	SetIdentity();
}
Mat3::Mat3(float x0, float x1, float x2,
	float y0, float y1, float y2,
	float z0, float z1, float z2) {
	m[0] = x0;   m[3] = y0;   m[6] = z0;
	m[1] = x1;   m[4] = y1;   m[7] = z1;
	m[2] = x2;   m[5] = y2;   m[8] = z2;
}

void Mat3::SetMatrix(float x0, float x1, float x2,
    float y0, float y1, float y2,
    float z0, float z1, float z2) {
	m[0] = x0;   m[3] = y0;   m[6] = z0;
	m[1] = x1;   m[4] = y1;   m[7] = z1;
	m[2] = x2;   m[5] = y2;   m[8] = z2;
}

void Mat3::SetIdentity() {
	SetMatrix(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

void Mat3::Print() const {

	std::cout << "\n" <<
		m[0] << "\t" << m[3] << "\t" << m[6] << "\t\n" <<
		m[1] << "\t" << m[4] << "\t" << m[7] << "\t\n" <<
		m[2] << "\t" << m[5] << "\t" << m[8] << std::endl;
}


Mat4::Mat4(){
	SetIdentity();
}

Mat4::Mat4(float x0, float y0, float z0, float w0,
	float x1, float y1, float z1, float w1,
	float x2, float y2, float z2, float w2,
	float x3, float y3, float z3, float w3) {

	m[0] = x0;   m[4] = y0;   m[8] = z0; m[12] = w0;
	m[1] = x1;   m[5] = y1;   m[9] = z1; m[13] = w1;
	m[2] = x2;   m[6] = y2;   m[10] = z2; m[14] = w2;
	m[3] = x3;   m[7] = y3;   m[11] = z3; m[15] = w3;
}

// set identity matrix
void Mat4::SetIdentity() {
	m[0] = 1.0f;   m[4] = 0.0f;   m[8] =  0.0f;   m[12] = 0.0f;
	m[1] = 0.0f;   m[5] = 1.0f;   m[9] =  0.0f;   m[13] = 0.0f;
	m[2] = 0.0f;   m[6] = 0.0f;   m[10] = 1.0f;   m[14] = 0.0f;
	m[3] = 0.0f;   m[7] = 0.0f;   m[11] = 0.0f;   m[15] = 1.0f;
}

// rotate the matrix in the x direction
void Mat4::RotateX(float angleInDegrees) {

	angleInDegrees = (angleInDegrees * PI) / 180;

	m[0] = 1.0f;   m[4] = 0.0f;					 m[8] = 0.0f;						m[12] = 0.0f;
	m[1] = 0.0f;   m[5] = cos(angleInDegrees);   m[9] = -sin(angleInDegrees);		m[13] = 0.0f;
	m[2] = 0.0f;   m[6] = sin(angleInDegrees);   m[10] = cos(angleInDegrees);		m[14] = 0.0f;
	m[3] = 0.0f;   m[7] = 0.0f;					 m[11] = 0.0f;						m[15] = 1.0f;
}

// rotate the matrix in the y direction
void Mat4::RotateY(float angleInDegrees) {

	angleInDegrees = (angleInDegrees * PI) / 180;


	m[0] = cos(angleInDegrees);   m[4] = 0.0f;		 m[8] = sin(angleInDegrees);	m[12] = 0.0f;
	m[1] = 0.0f;				  m[5] = 1.0f;		 m[9] = 0.0f;					m[13] = 0.0f;
	m[2] = -sin(angleInDegrees);  m[6] = 0.0f;		 m[10] = cos(angleInDegrees);	m[14] = 0.0f;
	m[3] = 0.0f;				  m[7] = 0.0f;		 m[11] = 0.0f;					m[15] = 1.0f;
}

// rotate the matrix in the z direction
void Mat4::RotateZ(float angleInDegrees) {

	angleInDegrees = (angleInDegrees * PI) / 180;

	m[0] = cos(angleInDegrees);   m[4] = sin(angleInDegrees);	 m[8] =  0.0f;		m[12] = 0.0f;
	m[1] = sin(angleInDegrees);	  m[5] = cos(angleInDegrees);	 m[9] =  0.0f;		m[13] = 0.0f;
	m[2] = 0.0f;				  m[6] = 0.0f;					 m[10] = 1.0f;		m[14] = 0.0f;
	m[3] = 0.0f;				  m[7] = 0.0f;					 m[11] = 0.0f;		m[15] = 1.0f;
}

// Scale the matrix
void Mat4::Scale(float x, float y, float z) {
	m[0] = x;			m[4] = 0.0f;	  m[8] = 0.0f;		m[12] = 0.0f;
	m[1] = 0.0f;	    m[5] = y;		  m[9] = 0.0f;		m[13] = 0.0f;
	m[2] = 0.0f;		m[6] = 0.0f;	  m[10] = z;		m[14] = 0.0f;
	m[3] = 0.0f;		m[7] = 0.0f;	  m[11] = 0.0f;		m[15] = 1.0f;
}

// translate the matrix
void Mat4::Translate(Vector3 translation) {
	m[0] = 1;			m[4] = 0.0f;	  m[8] = 0.0f;		m[12] = translation.x;
	m[1] = 0.0f;	    m[5] = 1;		  m[9] = 0.0f;		m[13] = translation.y;
	m[2] = 0.0f;		m[6] = 0.0f;	  m[10] = 1;		m[14] = translation.z;
	m[3] = 0.0f;		m[7] = 0.0f;	  m[11] = 0.0f;		m[15] = 1.0f;
}

// setting the matirx 
void Mat4::SetMatrix(float x0, float x1, float x2, float x3,
	float y0, float y1, float y2, float y3,
	float z0, float z1, float z2, float z3,
	float w0, float w1, float w2, float w3) {

	m[0] = x0;   m[4] = y0;   m[8] = z0; m[12] = w0;
	m[1] = x1;   m[5] = y1;   m[9] = z1; m[13] = w1;
	m[2] = x2;   m[6] = y2;   m[10] = z2; m[14] = w2;
	m[3] = x3;   m[7] = y3;   m[11] = z3; m[15] = w3;
}
// getting the Transpose
void Mat4::Transpose() {

	SetMatrix(m[0], m[4], m[8], m[12],
		m[1], m[5], m[9], m[13],
		m[2], m[6], m[10], m[14],
		m[3], m[7], m[11], m[15]);
}
// printing the matirx
void Mat4::Print() const {

	std::cout << "\n" <<
		m[0] << "\t" << m[4] << "\t" << m[8] << "\t" << m[12] << "\n" <<
		m[1] << "\t" << m[5] << "\t" << m[9] << "\t" << m[13] << "\n" <<
		m[2] << "\t" << m[6] << "\t" << m[10] << "\t" << m[14] << "\n" <<
		m[3] << "\t" << m[7] << "\t" << m[11] << "\t" << m[15] << std::endl;
}

// overloaded * operator to get the multiplication matrix
Mat4 Mat4::operator* (const Mat4& n) const {

	return Mat4(m[0] * n.m[0] + m[4] * n.m[1] + m[8] * n.m[2] + m[12] * n.m[3],
			    m[0] * n.m[4] + m[4] * n.m[5] + m[8] * n.m[6] + m[12] * n.m[7],
			   	m[0] * n.m[8] + m[4] * n.m[9] + m[8] * n.m[10]+ m[12] * n.m[11],
			    m[0] * n.m[12]+ m[4] * n.m[13]+ m[8] * n.m[14]+ m[12] * n.m[15],
				m[1] * n.m[0] + m[5] * n.m[1] + m[9] * n.m[2] + m[13] * n.m[3],
				m[1] * n.m[4] + m[5] * n.m[5] + m[9] * n.m[6] + m[13] * n.m[7],
				m[1] * n.m[8] + m[5] * n.m[9] + m[9] * n.m[10]+ m[13] * n.m[11],
				m[1] * n.m[12]+ m[5] * n.m[13]+ m[9] * n.m[14]+ m[13] * n.m[15],
				m[2] * n.m[0] + m[6] * n.m[1] + m[10]* n.m[2] + m[14] * n.m[3],
				m[2] * n.m[4] + m[6] * n.m[5] + m[10]* n.m[6] + m[14] * n.m[7],
				m[2] * n.m[8] + m[6] * n.m[9] + m[10]* n.m[10]+ m[14] * n.m[11],
				m[2] * n.m[12]+ m[6] * n.m[13]+ m[10]* n.m[14]+ m[14] * n.m[15],
				m[3] * n.m[0] + m[7] * n.m[1] + m[11]* n.m[2] + m[15] * n.m[3],
				m[3] * n.m[4] + m[7] * n.m[5] + m[11]* n.m[6] + m[15] * n.m[7],
				m[3] * n.m[8] + m[7] * n.m[9] + m[11]* n.m[10]+ m[15] * n.m[11],
				m[3] * n.m[12]+ m[7] * n.m[13]+ m[11]* n.m[14]+ m[15] * n.m[15]);
}

// multiplication of matirx and vector 4
Vector3 Mat4::operator*(const Vector4 v) const {

	float x = v.x * m[0] + v.y * m[4] + v.z * m[8] + 1.0f * m[12];
	float y = v.x * m[1] + v.y * m[5] + v.z * m[9] + 1.0f * m[13];
	float z = v.x * m[2] + v.y * m[6] + v.z * m[10] + 1.0f * m[14];
	return Vector3(x, y, z);
  

}

// getting the second order;
float Mat4::SecondOrder(float x1, float y1,
					   float x2, float y2) {
	float SecondOr = (x1 * y2) - (x2 * y1);
	return SecondOr;
}

// getting the third order
float Mat4::ThirdOrder(float x1, float y1, float z1,
					   float x2, float y2, float z2,
					   float x3, float y3, float z3) {

	float ThirsOr = (x1 * 1) *  SecondOrder(y2, z2, y3, z3) + 
		            (x2 * -1) * SecondOrder(y1, z1, y3, z3) + 
		            (x3 * 1) * SecondOrder(y1, z1, y2, z2);

	return ThirsOr;

}


//Returning the determinant of the matrix
float Mat4::Det() {

	float lastOrder = (m[0] ) *  ThirdOrder(m[5], m[9], m[13], m[6], m[10], m[14], m[7], m[11], m[15]) +
					  (m[1] ) *  ThirdOrder(m[4], m[8], m[12], m[6], m[10], m[14], m[7], m[11], m[15]) +
					  (m[2] )  * ThirdOrder(m[4], m[8], m[12], m[5], m[9], m[13], m[7], m[11], m[15]) +
					  (m[3] )  * ThirdOrder(m[4], m[8], m[12], m[5], m[9], m[13], m[6], m[10] , m[14]);

		return lastOrder; 
}


// set the inverse matrix
void Mat4::Inverse() {
	Mat4 inverseM;

	inverseM.m[0] = ThirdOrder(m[5], m[9], m[13],
		m[6], m[10], m[14],
		m[7], m[11], m[15]);

	inverseM.m[1] = ThirdOrder(m[4], m[8], m[12],
		m[6], m[10], m[14],
		m[7], m[11], m[15])* -1;

	inverseM.m[2] = ThirdOrder(m[4], m[8], m[12],
		m[5], m[9], m[13],
		m[7], m[11], m[15]);

	inverseM.m[3] = ThirdOrder(m[4], m[8], m[12],
		m[5], m[9], m[13],
		m[6], m[10], m[14]) * -1;

	inverseM.m[4] = ThirdOrder(m[1], m[9], m[13],
		m[2], m[10], m[14],
		m[3], m[11], m[15]) * -1;

	inverseM.m[5] = ThirdOrder(m[0], m[8], m[12],
		m[2], m[10], m[14],
		m[3], m[11], m[15]);

	inverseM.m[6] = ThirdOrder(m[0], m[8], m[12],
		m[1], m[9], m[13],
		m[3], m[11], m[15]) * -1;

	inverseM.m[7] = ThirdOrder(m[0], m[8], m[12],
		m[1], m[9], m[13],
		m[2], m[10], m[14]);
	
	inverseM.m[8] = ThirdOrder(m[1], m[5], m[13],
		m[2], m[6], m[14],
		m[3], m[7], m[15]);


	inverseM.m[9] = ThirdOrder(m[0], m[4], m[12],
		m[2], m[6], m[14],
		m[3], m[7], m[15]) * -1;

	inverseM.m[10] = ThirdOrder(m[0], m[4], m[12],
		m[1], m[5], m[13],
		m[3], m[7], m[15]);

	inverseM.m[11] = ThirdOrder(m[0], m[4], m[12],
		m[1], m[5], m[13],
		m[2], m[6], m[14]) * -1;

	inverseM.m[12] = ThirdOrder(m[1], m[5], m[9],
		m[2], m[6], m[10],
		m[3], m[7], m[11])* -1;

	inverseM.m[13] = ThirdOrder(m[0], m[4], m[8],
		m[2], m[6], m[10],
		m[3], m[7], m[11]);

	inverseM.m[14] = ThirdOrder(m[0], m[4], m[8],
		m[1], m[5], m[9],
		m[3], m[7], m[11])* -1;

	inverseM.m[15] = ThirdOrder(m[0], m[4], m[8],
		m[1], m[5], m[9],
		m[2], m[6], m[10]);

	inverseM.Transpose();

	for (int i = 0; i < 16; i++) {
		inverseM.m[i] /= Det();

	}
	
	for (int i = 0; i < 16; i++) {
		m[i] = inverseM.m[i];
	}

}
Mat4::~Mat4()
{

}
