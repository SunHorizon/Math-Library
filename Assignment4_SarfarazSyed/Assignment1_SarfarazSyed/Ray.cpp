#include "Ray.h"



Ray::Ray(Vector3 start_, Vector3 dir_)
{
	start = start_;
	dir = dir_;
}

Vector3 Ray::currentPosition(float t) {
	Vector3  currentPos;
	currentPos = start + dir * t;
	return currentPos;
}
Ray::~Ray()
{
}
