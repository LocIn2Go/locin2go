#pragma once

/*
	EuclidianCoordinate.h
	Created on: Jul 04, 2017
	Author: aleks

	Storage class for Euclidian/Cartesian coordinates. Because I was afraid of side effects I created getter and setter methods
*/

//#include "GeometricalUtils.h"

class EuclidianCoordinate
{
	//friend class GeometricalUtils;

	double x;
	double y;
	double z;
	
public:
	EuclidianCoordinate(const double coord_x, const double coord_y, const double coord_z);
	~EuclidianCoordinate();

	double get_x() const;
	double get_y() const;
	double get_z() const;

	void set_x(const double x);
	void set_y(const double y);
	void set_z(const double z);
		
};