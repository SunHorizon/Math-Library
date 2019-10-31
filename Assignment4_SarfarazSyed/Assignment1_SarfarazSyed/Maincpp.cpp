#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include "Vector3.h"
#include "Ray.h"
#include "Plane.h"
#include "Mat4.h"
#include "Quaternion.h"

using namespace std;
using namespace MATH;

int main(int argc, char *argv[]) {

	
	cout << "Quaternion * Quaternion" << endl;
	Quaternion q1(1, 2, 2 ,3);
	Quaternion q2(2, 1, 2, 5);
	Quaternion newQ = q1 * q2;
	cout << "["<<newQ.quaternion.x << ", " << newQ.quaternion.y << ", " << newQ.quaternion.z << ", " << newQ.quaternion.w << "]" << endl;

	cout << "" << endl;
	cout << "" << endl;
	cout << "Rotate" << endl;
	Quaternion q3(Vector3(0, 0, 1), 90.0);
	Vector3 v = Vector3(1, 0, 0);
	Vector3 result = q3.Rotate(v);
	cout << "[" << floor(result.x) << ", " << result.y << ", " << result.z <<  "]" << endl;

	cout << "" << endl;
	cout << "Slerp" << endl;
	cout << "" << endl;
	Quaternion q4(Vector3(0, 0, 1), 90.0);
	Quaternion q5(1, 0, 1, 0);
	Quaternion q7(-1, 0, 1, 0);
	Quaternion result1  = q5.Slerp(q7, 0.5);
	cout << "[" << result1.quaternion.x << ", " << result1.quaternion.y << ", " << result1.quaternion.z << ", " << result1.quaternion.w << "]" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	cout << "Convert to matrix" << endl;
	Quaternion q6(Vector3(1, 0, 0), 0);
	q6.ConvertToMatrix().Print();



	getchar();
}
