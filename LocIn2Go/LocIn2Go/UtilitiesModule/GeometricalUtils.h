/*
GeometricalUtils.h

Created on: July 05, 2016
Author: jelena
Adapted: aleks

Utilities related to geometry
*/

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <math.h>
#include "EuclidianCoordinate.h"
#include "SphericalCoordinate.h"
#include <iostream>

using namespace std;

class GeometricalUtils
{
public:
	GeometricalUtils();
	virtual ~GeometricalUtils();

	static double euclidianDistance3D(EuclidianCoordinate a, EuclidianCoordinate b);
	static double sphericalDistance3D(SphericalCoordinate a, SphericalCoordinate b);

	static EuclidianCoordinate sphericalToEuclidianCoordinates(SphericalCoordinate a);
	static SphericalCoordinate euclidianToSphericalCoordinates(EuclidianCoordinate a);

	static double euclidianDistance3Dcoordinates(double x1, double y1, double z1, double x2, double y2, double z2);
	static void checkIfPlanar(EuclidianCoordinate point_a, EuclidianCoordinate point_b, EuclidianCoordinate point_c, EuclidianCoordinate point_d);
	static double checkResultInEquations(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, double xcheck, double ycheck, double zcheck);
	static array<double, 2> minMaxSensorDistance(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4);


};






