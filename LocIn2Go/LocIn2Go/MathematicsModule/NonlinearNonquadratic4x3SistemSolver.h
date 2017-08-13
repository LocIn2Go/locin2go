/*
	NonlinearNonquadratic4x3SistemSolver.h
	Created on: Dec 23, 2016
	Author: jelena
	
	Multilateration solution algorithm for solving the position of "target"
	if given distances from 4 given sensors...
*/

#pragma once

#include <array>
#include "../UtilitiesModule/EuclidianCoordinate.h"
using namespace std;

class NonlinearNonquadratic4x3SistemSolver
{

public:
	NonlinearNonquadratic4x3SistemSolver();
	virtual ~NonlinearNonquadratic4x3SistemSolver();
	EuclidianCoordinate nonlinearNonquadratic3x4SystemSolver(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, bool debug);
	
private:
	array<array<double, 3>, 4> x_sensors; //array<double, 12> x_sensors;
	array<double, 4> d_sensors;
	array<double, 3> x_result; //actual result given for testing

	EuclidianCoordinate linearNonquadraticIterativeSolver(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, double xk, double yk, double zk, bool debug);
	EuclidianCoordinate linearNonquadraticDeterminantSolver(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, double xk, double yk, double zk, bool debug);

};
