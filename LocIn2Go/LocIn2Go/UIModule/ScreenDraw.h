#pragma once
class ScreenDraw
{
	double max_view_azimuth;
	double max_view_elevation;

	int* scr_mem_buffer;
	int screen_x_size, screen_y_size;

public:
	ScreenDraw();
	virtual ~ScreenDraw();

public:
	int drawPixel(int x, int y);
	int drawLinePointByPoint(int x1, int y1, int x2, int y2);
	int drawLine(int x1, int y1, int x2, int y2);
	int drawLine(int x_start, int y_start, double angle, int length);

};

