#ifndef SPHERE_SPHERE_H_
#define SPHERE_SPHERE_H_

#include "../Point.hpp"

#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
#include <iostream>

void sphere(float const& pRayon,short int const& pPara,short int const& pMer,float const& pX,
		float const& pY,float const& pZ,bool const& pPaupiere);

void drawHollowSphere(float radiusOuter, float radiusInner, int slices, int stacks);

#endif /* SPHERE_SPHERE_H_ */
