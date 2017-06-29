#pragma once

class IMUSensoryData
{
	// Acceleration (mg)
	double acc_x, acc_y, acc_z;
	// Gyro
	double gyro_x, gyro_y, gyro_z;
	// Magnetometer (deg/s)
	double deg_x, deg_y, deg_z;
	// Preassure (mBar)
	double press;
	// Temperature (degrees Celsius)
	double temperature;

public:

	IMUSensoryData(double acc_x, double acc_y, double acc_z,
					double gyro_x, double gyro_y, double gyro_z,
					double deg_x, double deg_y, double deg_z,
					double pressure, double temperature);

	virtual ~IMUSensoryData();

	// getters and setters
	double get_acc_x() const;
	void set_acc_x(const double acc_x);
	
	double get_acc_y() const;
	void set_acc_y(const double acc_y);

	double get_acc_z() const;
	void set_acc_z(const double acc_z);


	double get_gyro_x() const;
	void set_gyro_x(const double gyro_x);

	double get_gyro_y() const;
	void set_gyro_y(const double gyro_y);

	double get_gyro_z() const;
	void set_gyro_z(const double gyro_z);

	
	double get_deg_x() const;
	void set_deg_x(const double deg_x);

	double get_deg_y() const;
	void set_deg_y(const double deg_y);

	double get_deg_z() const;
	void set_deg_z(const double deg_z);


	double get_pressure() const;
	void set_pressure(const double pressure);

	double get_temperature() const;
	void set_temperature(const double temperature);


};

