/*
	MathUtils.h

	Created on: July 05, 2017
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

using namespace std;

class MathUtils
{
public:
	MathUtils();
	virtual ~MathUtils();

	static vector<string> split(const string &s, char delim);
	static array<double, 19> parseLineToSensorData(string line);
	static double det2(double a, double b, double c, double d);
	static double det3(double a, double b, double c, double d, double e, double f, double g, double h, double i);
	static double det4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double m, double n, double o, double p);

	static double checkResultInEquations(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, double xcheck, double ycheck, double zcheck);

private:
	static void splitHelper(const string &s, char delim, vector<string> &elems);

};

