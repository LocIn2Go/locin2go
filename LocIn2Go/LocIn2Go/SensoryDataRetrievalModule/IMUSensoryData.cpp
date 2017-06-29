#include "IMUSensoryData.h"

IMUSensoryData::IMUSensoryData(double acc_x, double acc_y, double acc_z,
	double gyro_x, double gyro_y, double gyro_z,
	double deg_x, double deg_y, double deg_z,
	double pressure, double temperature)
{

}

IMUSensoryData::~IMUSensoryData()
{

}

// getters and setters
double IMUSensoryData::get_acc_x() const
{
	return acc_x;
}
void IMUSensoryData::set_acc_x(const double acc_x)
{
	this->acc_x = acc_x;
}

double IMUSensoryData::get_acc_y() const
{
	return acc_y;
}
void IMUSensoryData::set_acc_y(const double acc_y)
{
	this->acc_y = acc_y;
}

double IMUSensoryData::get_acc_z() const
{
	return acc_z;
}
void IMUSensoryData::set_acc_z(const double acc_z)
{
	this->acc_z = acc_z;
}


double IMUSensoryData::get_gyro_x() const
{
	return gyro_x;
}
void IMUSensoryData::set_gyro_x(const double gyro_x)
{
	this->gyro_x = gyro_x;
}

double IMUSensoryData::get_gyro_y() const
{
	return gyro_y;
}
void IMUSensoryData::set_gyro_y(const double gyro_y)
{
	this->gyro_y = gyro_y;
}

double IMUSensoryData::get_gyro_z() const
{
	return gyro_z;
}
void IMUSensoryData::set_gyro_z(const double gyro_z)
{
	this->gyro_z = gyro_z;
}


double IMUSensoryData::get_deg_x() const
{
	return deg_x;
}
void IMUSensoryData::set_deg_x(const double deg_x)
{
	this->deg_x = deg_x;
}

double IMUSensoryData::get_deg_y() const
{
	return deg_y;
}
void IMUSensoryData::set_deg_y(const double deg_y)
{
	this->deg_y = deg_y;
}

double IMUSensoryData::get_deg_z() const
{
	return deg_z;
}
void IMUSensoryData::set_deg_z(const double deg_z)
{
	this->deg_z = deg_z;
}


double IMUSensoryData::get_pressure() const
{
	return press;
}
void IMUSensoryData::set_pressure(const double pressure)
{
	press = pressure;
}

double IMUSensoryData::get_temperature() const
{
	return temperature;
}
void IMUSensoryData::set_temperature(const double temperature)
{
	this->temperature = temperature;
}




