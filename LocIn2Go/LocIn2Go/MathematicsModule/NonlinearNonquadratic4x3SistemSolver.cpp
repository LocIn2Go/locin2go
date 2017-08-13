/*
	NonlinearNonquadratic4x3SistemSolver.h
	Created on: Dec 23, 2016
	Author: jelena

	Multilateration solution algorithm for solving the position of "target"
	if given distances from 4 given sensors...
*/

#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <vector>

#include <limits>

#include "NonlinearNonquadratic4x3SistemSolver.h"
#include "../UtilitiesModule/MathUtils.h"
#include "../UtilitiesModule/GeometricalUtils.h"

using namespace std;

NonlinearNonquadratic4x3SistemSolver::NonlinearNonquadratic4x3SistemSolver() {
}

NonlinearNonquadratic4x3SistemSolver::~NonlinearNonquadratic4x3SistemSolver() {
}

EuclidianCoordinate NonlinearNonquadratic4x3SistemSolver::linearNonquadraticIterativeSolver(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, double xk, double yk, double zk, bool debug)
{
	double a11 = 2 * (xk - x1);
	double a12 = 2 * (yk - y1);
	double a13 = 2 * (zk - z1);
	double b1 = pow(d1, 2) - pow(xk - x1, 2) - pow(yk - y1, 2) - pow(zk - z1, 2);
	double a21 = 2 * (xk - x2);
	double a22 = 2 * (yk - y2);
	double a23 = 2 * (zk - z2);
	double b2 = pow(d2, 2) - pow(xk - x2, 2) - pow(yk - y2, 2) - pow(zk - z2, 2);
	double a31 = 2 * (xk - x3);
	double a32 = 2 * (yk - y3);
	double a33 = 2 * (zk - z3);
	double b3 = pow(d3, 2) - pow(xk - x3, 2) - pow(yk - y3, 2) - pow(zk - z3, 2);
	double a41 = 2 * (xk - x4);
	double a42 = 2 * (yk - y4);
	double a43 = 2 * (zk - z4);
	double b4 = pow(d4, 2) - pow(xk - x4, 2) - pow(yk - y4, 2) - pow(zk - z4, 2);

	double A11 = a11*a11 + a21*a21 + a31*a31 + a41*a41;
	double A12 = a12*a11 + a22*a21 + a32*a31 + a42*a41;
	double A13 = a13*a11 + a23*a21 + a33*a31 + a43*a41;
	double B1 = b1*a11 + b2*a21 + b3*a31 + b4*a41;
	double A21 = a11*a12 + a21*a22 + a31*a32 + a41*a42;
	double A22 = a12*a12 + a22*a22 + a32*a32 + a42*a42;
	double A23 = a13*a12 + a23*a22 + a33*a32 + a43*a42;
	double B2 = b1*a12 + b2*a22 + b3*a32 + b4*a42;
	double A31 = a11*a13 + a21*a23 + a31*a33 + a41*a43;
	double A32 = a12*a13 + a22*a23 + a32*a33 + a42*a43;
	double A33 = a13*a13 + a23*a23 + a33*a33 + a43*a43;
	double B3 = b1*a13 + b2*a23 + b3*a33 + b4*a43;

	//array<double, 3> forBnorm;
	vector<double> forBnorm;
	forBnorm.push_back(fabs(-(A21 / A22)) + fabs(-(A31 / A33)));
	forBnorm.push_back(fabs(-(A12 / A11)) + fabs(-(A32 / A33)));
	forBnorm.push_back(fabs(-(A13 / A22)) + fabs(-(A23 / A33)));
	//forBnorm[0]=fabs(-(A21/A22))+fabs(-(A31/A33));
	//forBnorm[1]=fabs(-(A12/A11))+fabs(-(A32/A33));
	//forBnorm[2]=fabs(-(A13/A22))+fabs(-(A23/A33));
	//double Bnorm = *max_element(forBnorm, forBnorm + 2);
	double Bnorm = *max_element(forBnorm.begin(), forBnorm.end());
	if (debug){
		if (Bnorm < 1)
			cout << "Linear system: converges" << endl;
		else
			cout << "Bnorm: " << Bnorm << endl;
	}

	double Cnorm = fabs(B1 / A11) + fabs(B2 / A22) + fabs(B3 / A33);
	int k = ceil((log((pow(10, -3) / Cnorm) * (1 - Bnorm)) / log(Bnorm)) - 1);
	if (debug)
		cout << "Linear system: iteration needed: " << k << endl;

	double d1r = B1 / A11; //the first iteration or the solution
	double d2r = B2 / A22;
	double d3r = B3 / A33;
	double d1k; //working iteration
	double d2k;
	double d3k;

	for (int i = 0; i <= 1000; i++){ // <=k
		d1k = -(A12 / A11)*d2r - (A13 / A11)*d3r + B1 / A11;
		d2k = -(A21 / A22)*d1r - (A23 / A22)*d3r + B2 / A22;
		d3k = -(A31 / A33)*d1r - (A32 / A33)*d2r + B3 / A33;
		d1r = d1k;
		d2r = d2k;
		d3r = d3k;
		if (debug)
			cout << "Linear iterations:" << d1r << "," << d2r << "," << d3r << endl;
	}

	EuclidianCoordinate result(d1r, d2r, d3r);
	return result;
}

EuclidianCoordinate NonlinearNonquadratic4x3SistemSolver::linearNonquadraticDeterminantSolver(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, double xk, double yk, double zk, bool debug){
	double a11 = 2 * (xk - x1);
	double a12 = 2 * (yk - y1);
	double a13 = 2 * (zk - z1);
	double b1 = pow(d1, 2) - pow(xk - x1, 2) - pow(yk - y1, 2) - pow(zk - z1, 2);
	double a21 = 2 * (xk - x2);
	double a22 = 2 * (yk - y2);
	double a23 = 2 * (zk - z2);
	double b2 = pow(d2, 2) - pow(xk - x2, 2) - pow(yk - y2, 2) - pow(zk - z2, 2);
	double a31 = 2 * (xk - x3);
	double a32 = 2 * (yk - y3);
	double a33 = 2 * (zk - z3);
	double b3 = pow(d3, 2) - pow(xk - x3, 2) - pow(yk - y3, 2) - pow(zk - z3, 2);
	double a41 = 2 * (xk - x4);
	double a42 = 2 * (yk - y4);
	double a43 = 2 * (zk - z4);
	double b4 = pow(d4, 2) - pow(xk - x4, 2) - pow(yk - y4, 2) - pow(zk - z4, 2);

	double A11 = a11*a11 + a21*a21 + a31*a31 + a41*a41;
	double A12 = a12*a11 + a22*a21 + a32*a31 + a42*a41;
	double A13 = a13*a11 + a23*a21 + a33*a31 + a43*a41;
	double B1 = b1*a11 + b2*a21 + b3*a31 + b4*a41;
	double A21 = a11*a12 + a21*a22 + a31*a32 + a41*a42;
	double A22 = a12*a12 + a22*a22 + a32*a32 + a42*a42;
	double A23 = a13*a12 + a23*a22 + a33*a32 + a43*a42;
	double B2 = b1*a12 + b2*a22 + b3*a32 + b4*a42;
	double A31 = a11*a13 + a21*a23 + a31*a33 + a41*a43;
	double A32 = a12*a13 + a22*a23 + a32*a33 + a42*a43;
	double A33 = a13*a13 + a23*a23 + a33*a33 + a43*a43;
	double B3 = b1*a13 + b2*a23 + b3*a33 + b4*a43;

	double D = MathUtils::det3(A11, A12, A13, A21, A22, A23, A31, A32, A33);
	double D1 = MathUtils::det3(B1, A12, A13, B2, A22, A23, B3, A32, A33);
	double D2 = MathUtils::det3(A11, B1, A13, A21, B2, A23, A31, B3, A33);
	double D3 = MathUtils::det3(A11, A12, B1, A21, A22, B2, A31, A32, B3);
	
	EuclidianCoordinate result(D1 / D, D2 / D, D3 / D);

	return result;
}

EuclidianCoordinate NonlinearNonquadratic4x3SistemSolver::nonlinearNonquadratic3x4SystemSolver(double x1, double y1, double z1, double d1, double x2, double y2, double z2, double d2, double x3, double y3, double z3, double d3, double x4, double y4, double z4, double d4, bool debug){
	vector<double> results;
	double newDistance1;
	double newDistance2;
	double newDistance3;
	double newDistance4;
	double totalDistanceDiff;
	double resultInEquationsDiff;

	EuclidianCoordinate X1(x1, y1, z1);
	EuclidianCoordinate X2(x2, y2, z2);
	EuclidianCoordinate X3(x3, y3, z3);
	EuclidianCoordinate X4(x4, y4, z4);

	if (debug){
		array<double, 2> minMax = GeometricalUtils::minMaxSensorDistance(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
		cout << "Minimum sensor distance is: " << minMax[0] << endl;
		cout << "Maximum sensor distance is: " << minMax[1] << endl;
	}

	if (debug)
		GeometricalUtils::checkIfPlanar(X1, X2, X3, X4);
	
	array<EuclidianCoordinate, 4> xSensors = { X1, X2, X3, X4 };

	EuclidianCoordinate XC(0, 0, 0); //global centeroid
	EuclidianCoordinate XCdiam(0, 0, 0);
	/*for (int i = 0; i < 3; i++)
	{ //3-dim
		double helpSum = 0;
		for (int j = 0; j < 4; j++) //4 sensors
			helpSum = helpSum + xSensors[j][i];
		XC[i] = (1.0 / 4.0) * (helpSum);
		XCdiam[i] = -XC[i];
	}
	*/
	
	double helpSumX = 0;
	double helpSumY = 0;
	double helpSumZ = 0;
	for (int j = 0; j < 4; j++) // Go through sensors
	{
		helpSumX += xSensors[j].get_x();
		helpSumY += xSensors[j].get_y();
		helpSumZ += xSensors[j].get_z();

	}
	
	//XC[i] = (1.0 / 4.0) * (helpSum);
	XC.set_x(0.25 * helpSumX);
	XC.set_y(0.25 * helpSumY);
	XC.set_z(0.25 * helpSumZ);

	//XCdiam[i] = -XC[i];
	XCdiam.set_x(-XC.get_x());
	XCdiam.set_y(-XC.get_y());
	XCdiam.set_z(-XC.get_z());



	array<EuclidianCoordinate, 2> startingPoints = { XC, XCdiam };
	EuclidianCoordinate result(0, 0, 0);
	int iteration = 1;
	int reset = 0;
	int n = sizeof(startingPoints) / sizeof(startingPoints[0]);
	bool again = true;

	for (int i = 0; i < n; i++){
		double xk = startingPoints[i].get_x(); //starting value
		double yk = startingPoints[i].get_y();
		double zk = startingPoints[i].get_z();
		double xk1; //next iteration
		double yk1;
		double zk1;
		
		EuclidianCoordinate delta_xyz = NonlinearNonquadratic4x3SistemSolver::linearNonquadraticDeterminantSolver(x1, y1, z1, d1, x2, y2, z2, d2, x3, y3, z3, d3, x4, y4, z4, d4, xk, yk, zk, debug);
		xk1 = xk + delta_xyz.get_x();
		yk1 = yk + delta_xyz.get_y();
		zk1 = zk + delta_xyz.get_z();
		while (fabs(xk1 - xk) > 0.0001 || fabs(yk1 - yk) > 0.0001 || fabs(zk1 - zk) > 0.0001){
			xk = xk1;
			yk = yk1;
			zk = zk1;
			delta_xyz = NonlinearNonquadratic4x3SistemSolver::linearNonquadraticDeterminantSolver(x1, y1, z1, d1, x2, y2, z2, d2, x3, y3, z3, d3, x4, y4, z4, d4, xk, yk, zk, debug);
			xk1 = xk + delta_xyz.get_x();
			yk1 = yk + delta_xyz.get_y();
			zk1 = zk + delta_xyz.get_z();
			iteration++;
			//cout << "Nonlinear iteration:" << xk1 << "," << yk1 << "," << zk1 << endl;
		}
		if (debug)
			cout << "Nonlinear system: iteration needed: " << iteration << " with reset: " << reset << endl;
		result.set_x(xk1);
		result.set_y(yk1);
		result.set_z(zk1);
		newDistance1 = GeometricalUtils::euclidianDistance3D(result, X1);
		newDistance2 = GeometricalUtils::euclidianDistance3D(result, X2);
		newDistance3 = GeometricalUtils::euclidianDistance3D(result, X3);
		newDistance4 = GeometricalUtils::euclidianDistance3D(result, X4);
		totalDistanceDiff = fabs(newDistance1 - d1) + fabs(newDistance2 - d2) + fabs(newDistance3 - d3) + fabs(newDistance4 - d4);
		if (debug)
			resultInEquationsDiff = GeometricalUtils::checkResultInEquations(x1, y1, z1, d1, x2, y2, z2, d2, x3, y3, z3, d3, x4, y4, z4, d4, result.get_x(), result.get_y(), result.get_z());
		//if(fabs(newDistance1-d1)<0.0025 && fabs(newDistance2-d2)<0.0025 && fabs(newDistance3-d3)<0.0025 && fabs(newDistance4-d4)<0.0025){// && Utils::checkResultInEquations(x1,y1,z1,d1,x2,y2,z2,d2,x3,y3,z3,d3,x4,y4,z4,d4,result[0],result[1],result[2]) < 0.8){
		if (totalDistanceDiff < 0.011){
			if (debug){
				cout << "Result: " << result.get_x() << "," << result.get_y() << "," << result.get_z() << endl;
				cout << "System accuracy (sum): " << resultInEquationsDiff << endl;
				cout << "Total distance diff: " << totalDistanceDiff << endl;
			}
			//break;
			if (results.size() == 0){
				results.push_back(totalDistanceDiff);
				results.push_back(result.get_x());
				results.push_back(result.get_y());
				results.push_back(result.get_z());
			}
			else {
				int resSize = results.size();
				for (int j = 0; j < resSize; j++){
					if (GeometricalUtils::euclidianDistance3Dcoordinates(result.get_x(), result.get_y(), result.get_z(), results[j * 4 + 1], results[j * 4 + 2], results[j * 4 + 3]) > 0.1){
						results.push_back(totalDistanceDiff);
						results.push_back(result.get_x());
						results.push_back(result.get_y());
						results.push_back(result.get_z());
					}
					j = j + 4;
				}
			}
		}/*else{
		 if(debug){
		 cout << "Result not: " << result[0] << "," << result[1] << "," << result[2] << endl;
		 cout << "System accuracy (sum): " << resultInEquationsDiff << endl;
		 cout << "Total distance diff: " << totalDistanceDiff << endl;
		 }
		 if(i<n-1)
		 reset++;
		 else {
		 //if(totalDistanceDiff>=0.009 || resultInEquationsDiff >= 0.8)
		 cout << "No more resets" << ", total distance diff: " << totalDistanceDiff << ", system accuracy: " << resultInEquationsDiff << endl;
		 }
		 }*/

		//test
		/*if(i==n-1 && again == true){
		int resIndex = 0;
		for(int j = 0; j < results.size(); j ++){
		if(results.size()>4 && results[resIndex] > results[j*4+4])
		resIndex = results[j*4+4];
		j = j+4;
		}
		if((results.size()>0 && results[resIndex]>1.0) || results.size()==0){
		i=i-2;
		for(int j = 0; j < 3; j++){ //3-dim
		XC[i] = XC[i]*100.0;
		XCdiam[i] = XCdiam[i]*100.0;;
		}
		continue;
		}
		again = false;
		cout << "Again" << endl;
		}*/
	}
	cout << "Nonlinear system: iteration needed: " << iteration << endl;
	/*cout << "Total distance diff: " << totalDistanceDiff << endl;
	cout << "Nonlinear system: iteration needed: " << iteration << endl;
	cout << "Nonlinear system: resets needed: " << reset << endl;
	if(debug){
	cout << "System accuracy (sum): " << resultInEquationsDiff << endl;
	cout << "Total distance diff: " << totalDistanceDiff << endl;
	}*/
	if (true){
		cout << "Number of results: " << results.size() / 4 << endl;
		cout << "Result vector (totalDistanceDiff,x,y,z): ";
		for (int i = 0; i < results.size(); i++)
			cout << results[i] << ", ";
		cout << endl;
	}
	int resIndex = 0;
	for (int i = 0; i < results.size(); i++){
		if (results.size()>4 && results[resIndex] > results[i * 4 + 4])
			resIndex = results[i * 4 + 4];
		i = i + 4;
	}
	if (results.size() > 0){
		result.set_x(results[resIndex + 1]);
		result.set_y(results[resIndex + 2]);
		result.set_z(results[resIndex + 3]);
		cout << "Total distance diff: " << results[resIndex] << endl;
	}
	else {
		
		// Proper way would be to throw exception
		cout << "No result!" << endl;

		result.set_x(std::numeric_limits<double>::quiet_NaN());
		result.set_y(std::numeric_limits<double>::quiet_NaN());
		result.set_z(std::numeric_limits<double>::quiet_NaN());
	}
	return result;
}
