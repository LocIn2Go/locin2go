#include "SphericalCoordinate.h"


SphericalCoordinate::SphericalCoordinate(const double coord_r, const double coord_theta, const double coord_phi)
{
	r = coord_r;
	theta = coord_theta;
	phi = coord_phi;
}

SphericalCoordinate::~SphericalCoordinate()
{
}


double SphericalCoordinate::get_r() const
{
	return r;
}

double SphericalCoordinate::get_theta() const
{
	return theta;
}

double SphericalCoordinate::get_phi() const
{
	return phi;
}

void SphericalCoordinate::set_r(const double coord_r)
{
	r = coord_r;
}

void SphericalCoordinate::set_theta(const double coord_theta)
{
	theta = coord_theta;
}

void SphericalCoordinate::set_phi(const double coord_phi)
{
	phi = coord_phi;
}

;