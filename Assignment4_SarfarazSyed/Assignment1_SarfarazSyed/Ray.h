#ifndef Ray_H
#define Ray_H
#include "Vector3.h"
#include <math.h>

using namespace MATH;
	class Ray
	{
	public:

		Vector3 start;
		Vector3 dir;
		Ray(Vector3 start_, Vector3 dir_);
		Vector3 currentPosition(float t);
		~Ray();
	};

#endif
