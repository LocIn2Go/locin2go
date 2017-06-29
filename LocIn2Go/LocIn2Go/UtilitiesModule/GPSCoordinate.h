#pragma once
class GPSCoordinate
{
	double latitude;		// from +90.0° (for North) to -90.0° (negative for South values) - default value will be -180°
	double longitude;		// Prime Meridian to +180° eastward and +180° westward - default value will be -180°
	double altitude;		// By definition, distance from the surface. default, therefore -15000m
	// long long timestamp;			// this might be necesary...

public:
	GPSCoordinate(const double latitude = -180.0, const double longitude = -360.0, const double altitude = -15000.0);
	~GPSCoordinate();

	double get_latitude() const;
	double get_longitude() const;
	double get_altitude() const;

	void set_latitude(const double latitude);
	void set_longitude(const double longitude);
	void set_altitude(const double altitude);

	bool is_valid() const;
};

