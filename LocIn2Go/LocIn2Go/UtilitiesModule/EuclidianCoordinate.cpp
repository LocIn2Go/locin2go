#include "EuclidianCoordinate.h"

EuclidianCoordinate::EuclidianCoordinate(const double coord_x, const double coord_y, const double coord_z)
{
	x = coord_x;
	y = coord_y;
	z = coord_z;
}

EuclidianCoordinate::~EuclidianCoordinate()
{
}

double EuclidianCoordinate::get_x() const
{
	return x;
}

double EuclidianCoordinate::get_y() const
{
	return y;
}

double EuclidianCoordinate::get_z() const
{
	return z;
}

void EuclidianCoordinate::set_x(const double coord_x)
{
	this->x = coord_x;
}

void EuclidianCoordinate::set_y(const double coord_y)
{
	this->y = coord_y;
}

void EuclidianCoordinate::set_z(const double coord_z)
{
	this->z = coord_z;
}

;