#pragma once

#include <time.h>

class GPSSensoryData
{
	
public:

	enum FIX_STATUS{ STATUS_NONE, STATUS_EST, STATUS_TIME_ONLY, STATUS_STD, STATUS_DGPS };

	GPSSensoryData(FIX_STATUS stat, double lat, double lon, double alt, double speed = 0.0,
						double heading = 0.0, int DOP = 50.0, int sat_cnt = 0, time_t t = NULL, int utc_time = 0);
	
	virtual ~GPSSensoryData();

	// getters and setters
	
	FIX_STATUS get_status() const;
	void set_status(const FIX_STATUS stat);

	double get_latitude() const;
	void set_latitude(const double lat);

	double get_longitude() const;
	void set_longitude(const double lon);

	double get_altitude() const;
	void set_altitude(const double alt);

	double get_speed() const;
	void set_speed(const double speed);

	double get_heading() const;
	void set_heading(const double heading);

	int get_DOP() const;
	void set_DOP(const int DOP);

	int get_satellites_count() const;
	void set_satellites_count(const int sat_cnt);

	time_t get_time() const;
	void set_time(const time_t t);

	int get_UTC_time_sec() const;
	void set_UTC_time_sec(const int utc_time);

private:

	FIX_STATUS status;
	double latitude, longitude, altitude;
	double speed;
	double heading;
	int DOP;		// Dillution of precision
	int satellites_count;
	time_t time;
	int UTC_time_sec;

};

