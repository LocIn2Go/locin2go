#include "GPSCoordinate.h"

GPSCoordinate::GPSCoordinate(const double latitude, const double longitude, const double altitude)
{
	this->latitude = latitude;
	this->longitude = longitude;
	this->altitude = altitude;
}

GPSCoordinate::~GPSCoordinate()
{
}

double GPSCoordinate::get_latitude() const
{
	return latitude;
}

double GPSCoordinate::get_longitude() const
{
	return longitude;
}

double GPSCoordinate::get_altitude() const
{
	return altitude;
}

void GPSCoordinate::set_latitude(const double latitude)
{
	this->latitude = latitude;
}

void GPSCoordinate::set_longitude(const double longitude)
{
	this->longitude = longitude;
}

void GPSCoordinate::set_altitude(const double altitude)
{
	this->altitude = altitude;
}

bool GPSCoordinate::is_valid() const
{
	return latitude <= 90.0 && latitude >= -90.0 && longitude <= 180.0 && longitude >= -180.0 && altitude >= 11000.0;
}

;