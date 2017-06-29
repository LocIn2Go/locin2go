#include "GPSSensoryData.h"


GPSSensoryData::GPSSensoryData(FIX_STATUS stat, double lat, double lon, double alt, double speed,
	double heading, int DOP, int sat_cnt, time_t t, int utc_time)
{
	status = stat;
	latitude = lat;
	longitude = lon;
	altitude = alt;
	this->speed = speed;
	this->heading = heading;
	this->DOP = DOP;
	satellites_count = sat_cnt;
	time = t;
	UTC_time_sec = utc_time;
}

GPSSensoryData::~GPSSensoryData()
{
}

GPSSensoryData::FIX_STATUS GPSSensoryData::get_status() const
{
	return status;
}

void GPSSensoryData::set_status(const FIX_STATUS stat)
{
	status = stat;
}

double GPSSensoryData::get_latitude() const
{
	return latitude;
}

void GPSSensoryData::set_latitude(const double lat)
{
	latitude = lat;
}

double GPSSensoryData::get_longitude() const
{
	return longitude;
}

void GPSSensoryData::set_longitude(const double lon)
{
	longitude = lon;
}

double GPSSensoryData::get_altitude() const
{
	return altitude;
}

void GPSSensoryData::set_altitude(const double alt)
{
	altitude = alt;
}

double GPSSensoryData::get_speed() const
{
	return speed;
}

void GPSSensoryData::set_speed(const double speed)
{
	this->speed = speed;
}

double GPSSensoryData::get_heading() const
{
	return heading;
}
void GPSSensoryData::set_heading(const double heading)
{
	this->heading = heading;
}

int GPSSensoryData::get_DOP() const
{
	return DOP;
}
void GPSSensoryData::set_DOP(const int DOP)
{
	this->DOP = DOP;
}

int GPSSensoryData::get_satellites_count() const
{
	return satellites_count;
}

void GPSSensoryData::set_satellites_count(const int sat_cnt)
{
	satellites_count = sat_cnt;
}

time_t GPSSensoryData::get_time() const
{
	return time;
}

void GPSSensoryData::set_time(const time_t t)
{
	time = t;
}

int GPSSensoryData::get_UTC_time_sec() const
{
	return UTC_time_sec;
}

void GPSSensoryData::set_UTC_time_sec(const int utc_time)
{
	UTC_time_sec = utc_time;
}

