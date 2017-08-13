/*
	MathUtils.cpp
	
	Created on: Dec 23, 2016
	Author: jelena
	Adapted on: Jul 06, 2017
	Adaptor: alex

*/

#include "MathUtils.h"


MathUtils::MathUtils()
{
}


MathUtils::~MathUtils()
{
}

void MathUtils::splitHelper(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

vector<string> MathUtils::split(const string &s, char delim) {
	vector<string> elems;
	splitHelper(s, delim, elems);
	return elems;
}

array<double, 19> MathUtils::parseLineToSensorData(string line){
	array<double, 19> data;
	vector<string> xSplit = MathUtils::split(line, ';'); //38.3416,6.68422,41.7486:74.4656;

	for (int i = 0; i < 4; i++) {
		vector<string> xd = MathUtils::split(xSplit[i], ':');
		vector<string> x = MathUtils::split(xd[0], ',');
		data[i * 4 + 0] = atof(x[0].c_str()); //string to double
		data[i * 4 + 1] = atof(x[1].c_str());
		data[i * 4 + 2] = atof(x[2].c_str());
		data[i * 4 + 3] = atof(xd[1].c_str());
	}

	if (xSplit.size() == 5){
		vector<string> xd = MathUtils::split(xSplit[4], ':');
		vector<string> x = MathUtils::split(xd[0], ',');
		data[16] = atof(x[0].c_str()); //string to double
		data[17] = atof(x[1].c_str());
		data[18] = atof(x[2].c_str());
	}

	return data;
}

double MathUtils::det2(double a, double b, double c, double d){
	return a*d - b*c;
}

double MathUtils::det3(double a, double b, double c, double d, double e, double f, double g, double h, double i){
	return a*det2(e, f, h, i) - b*det2(d, f, g, i) + c*det2(d, e, g, h);
}

double MathUtils::det4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double m, double n, double o, double p){
	return a*det3(f, g, h, j, k, l, n, o, p) - b*det3(e, g, h, i, k, l, m, o, p) + c*det3(e, f, h, i, j, l, m, n, p) - d*det3(e, f, g, i, j, k, m, n, o);
}

;