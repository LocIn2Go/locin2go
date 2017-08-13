#include "GeometricalUtils.h"

/*
	GeometricalUtils.cpp

	Created on: Dec 23, 2016
	Author: jelena
	Adapted on: July 06, 2017
	Adapted: alex
	
	Utilities related to spacial calculations such as distance in euclidian/cardesian, spherical or other coordinate systems
*/

GeometricalUtils::GeometricalUtils()
{
}


GeometricalUtils::~GeometricalUtils()
{
}

double GeometricalUtils::euclidianDistance3D(EuclidianCoordinate a, EuclidianCoordinate b)
{
	return sqrt(pow(a.get_x() - b.get_x(), 2) + pow(a.get_y() - b.get_y(), 2) + pow(a.get_z() - b.get_z(), 2));
}

double GeometricalUtils::sphericalDistance3D(SphericalCoordinate a, SphericalCoordinate b)
{
	return sqrt(pow(a.r, 2) + pow(b.r, 2) - 2 * a.r * b.r * ( sin(a.theta) * sin(b.theta) * cos (a.phi - b.phi) + cos(a.theta) * cos(b.theta) ));
}

EuclidianCoordinate GeometricalUtils::sphericalToEuclidianCoordinates(SphericalCoordinate a)
{
	return EuclidianCoordinate(	a.r * cos(a.theta) * sin (a.phi),
								a.r * sin (a.theta) * sin(a.phi),
								a.r * cos(a.phi) );
}

SphericalCoordinate GeometricalUtils::euclidianToSphericalCoordinates(EuclidianCoordinate a)
{
	double x = a.get_x();
	double y = a.get_y();
	double z = a.get_z();

	return SphericalCoordinate(	sqrt(x * x + y * y + z * z),
								atan2(y, x),
								atan2(z, sqrt(x * x + y * y + z * z)) );
}

double GeometricalUtils::euclidianDistance3Dcoordinates(double x1, double y1, double z1, double x2, double y2, double z2)
{
	double sum = pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2);
	return sqrt(sum);
}

void GeometricalUtils::checkIfPlanar(EuclidianCoordinate point_a, EuclidianCoordinate point_b, EuclidianCoordinate point_c, EuclidianCoordinate point_d){
	//create x1x2x3 plane and check if x4 is on it
	double ax = point_a.get_x();
	double ay = point_a.get_y();
	double az = point_a.get_z();

	double bx = point_b.get_x();
	double by = point_b.get_y();
	double bz = point_b.get_z();

	double cx = point_c.get_x();
	double cy = point_c.get_y();
	double cz = point_c.get_z();

	double dx = point_d.get_x();
	double dy = point_d.get_y();
	double dz = point_d.get_z();

	double c = ((ax - bx) * (cy * ax - ay * cx) - (ax - cx) * (by * ax - ay * bx)) / ((cz * ax - az * cx) * (by * ax - ay * bx) - (bz * ax - az * bx) * (cy * ax - ay * cx));
	//double c = ((x[0] - y[0])	* (z[1] * x[0] - x[1] * z[0]) - (x[0] - z[0]) * (y[1] * x[0] - x[1] * y[0])) / ((z[2] * x[0] - x[2] * z[0]) * (y[1] * x[0] - x[1] * y[0]) - (y[2] * x[0] - x[2] * y[0])	* (z[1] * x[0] - x[1] * z[0]));
	double b = (ax - c * (az * bx - bz * ax ) - bx) / (ay * bx - by * ax);
	//double b = (x[0] - c * (x[2] * y[0] - y[2] * x[0]) - y[0]) / (x[1] * y[0] - y[1] * x[0]);
	double a = -1.0 / ax - b * ay / ax - c * az / ax;
	//double a = -1.0 / x[0] - b * x[1] / x[0] - c * x[2] / x[0];

	//plane: ax+by+cz+1=0 -> z=(-1-ax-by)/c
	double expected = (-1 - a * dx - b * dy) / c;
	//double expected = (-1 - a * check[0] - b * check[1]) / c;

	bool result = false;
	
	//distance fourth dot of a plane
	double distance = fabs(a * dx + b * dy + c * dz) / pow(pow(a, 2) + pow(b, 2) + pow(c, 2), 0.5);
	//double distance = fabs(a * check[0] + b * check[1] + c * check[2])  / pow(pow(a, 2) + pow(b, 2) + pow(c, 2), 0.5);
	if (distance < 0.01)
		result = true;
	// This should be logged
	//cout << "sensors on plane: " << result << ", distance: " << distance << endl;
}

double GeometricalUtils::checkResultInEquations(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, double xcheck, double ycheck, double zcheck){
	//(x-x1)^2+(y-y1)^2+(z-z1)^2=d1^2 - four equations
	double pom1 = pow(d1, 2) - pow(xcheck - x1, 2) - pow(ycheck - y1, 2) - pow(zcheck - z1, 2);
	double pom2 = pow(d2, 2) - pow(xcheck - x2, 2) - pow(ycheck - y2, 2) - pow(zcheck - z2, 2);
	double pom3 = pow(d3, 2) - pow(xcheck - x3, 2) - pow(ycheck - y3, 2) - pow(zcheck - z3, 2);
	double pom4 = pow(d4, 2) - pow(xcheck - x4, 2) - pow(ycheck - y4, 2) - pow(zcheck - z4, 2);
	//cout << "1 - accuracy: " << pom1 << ", 2 - accuracy: " << pom2 << ", 3 - accuracy: " << pom3 << ", 4 - accuracy: " << pom4 << endl;
	//cout << "system accuracy: " << fabs(pom1)+fabs(pom2)+fabs(pom3)+fabs(pom4) << endl;
	return fabs(pom1) + fabs(pom2) + fabs(pom3) + fabs(pom4);
}

array<double, 2> GeometricalUtils::minMaxSensorDistance(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4){
	
	EuclidianCoordinate X1(x1, y1, z1);
	EuclidianCoordinate X2(x2, y2, z2);
	EuclidianCoordinate X3(x3, y3, z3);
	EuclidianCoordinate X4(x4, y4, z4);

	double min;
	double max;

	double d1 = GeometricalUtils::euclidianDistance3D(X1, X2);
	min = d1;
	max = d1;
	double d2 = GeometricalUtils::euclidianDistance3D(X1, X3);
	if (d2 < min)
		min = d2;
	if (d2 > max)
		max = d2;
	double d3 = GeometricalUtils::euclidianDistance3D(X1, X4);
	if (d3 < min)
		min = d3;
	if (d3 > max)
		max = d3;
	double d4 = GeometricalUtils::euclidianDistance3D(X2, X3);
	if (d4 < min)
		min = d4;
	if (d4 > max)
		max = d4;
	double d5 = GeometricalUtils::euclidianDistance3D(X2, X4);
	if (d5 < min)
		min = d5;
	if (d5 > max)
		max = d5;
	double d6 = GeometricalUtils::euclidianDistance3D(X3, X4);
	if (d6 < min)
		min = d6;
	if (d6 > max)
		max = d6;

	array<double, 2> minMax = { min, max };
	return minMax;
}