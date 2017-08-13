#pragma once

/*
	EuclidianCoordinate.h
	Created on: Jul 06, 2017
	Author: aleks

	Storage class for Spherical coordinates. Because I was afraid of side effects I created getter and setter methods
*/

//#include "GeometricalUtils.h"

class SphericalCoordinate
{
	friend class GeometricalUtils;

	double r;		// Distance to the point from coordinate beginning
	double theta;	// Azimuthal angle (in xy plane from positive side of the x axis)
	double phi;		// Spacial angle from the positive side of z axis to the position vector

public:
	SphericalCoordinate(const double coord_r, const double coord_theta, const double coord_phi);
	virtual ~SphericalCoordinate();

	double get_r() const;
	double get_theta() const;
	double get_phi() const;

	void set_r(const double r);
	void set_theta(const double theta);
	void set_phi(const double phi);

};
