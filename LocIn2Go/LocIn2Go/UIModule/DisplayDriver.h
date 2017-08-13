
/*
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
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class DisplayDriver
{

public:

	DisplayDriver(short int width, short int height);
	virtual ~DisplayDriver();
	// This MUST be defined by the subclass:
	virtual void drawPixel(short int x, short int y, unsigned short int color) = 0;

	// TRANSACTION API / CORE DRAW API
	// These MAY be overridden by the subclass to provide device-specific
	// optimized code.  Otherwise 'generic' versions are used.
	virtual void startWrite(void);
	virtual void writePixel(short int x, short int y, unsigned short int color);
	virtual void writeFillRect(short int x, short int y, short int w, short int h, unsigned short int color);
	virtual void writeFastVLine(short int x, short int y, short int h, unsigned short int color);
	virtual void writeFastHLine(short int x, short int y, short int w, unsigned short int color);
	virtual void writeLine(short int x0, short int y0, short int x1, short int y1, unsigned short int color);
	virtual void endWrite(void);

	// CONTROL API
	// These MAY be overridden by the subclass to provide device-specific
	// optimized code.  Otherwise 'generic' versions are used.
	virtual void setRotation(unsigned char r);
	virtual void invertDisplay(bool i);

	// BASIC DRAW API
	// These MAY be overridden by the subclass to provide device-specific
	// optimized code.  Otherwise 'generic' versions are used.
	virtual void
		// It's good to implement those, even if using transaction API
		drawFastVLine(short int x, short int y, short int h, unsigned short int color),
		drawFastHLine(short int x, short int y, short int w, unsigned short int color),
		fillRect(short int x, short int y, short int w, short int h, unsigned short int color),
		fillScreen(unsigned short int color),
		// Optional and probably not necessary to change
		drawLine(short int x0, short int y0, short int x1, short int y1, unsigned short int color),
		drawRect(short int x, short int y, short int w, short int h, unsigned short int color);

	// These exist only with Adafruit_GFX (no subclass overrides)
	void
		drawCircle(short int x0, short int y0, short int r, unsigned short int color),
		drawCircleHelper(short int x0, short int y0, short int r, unsigned char cornername,
		unsigned short int color),
		fillCircle(short int x0, short int y0, short int r, unsigned short int color),
		fillCircleHelper(short int x0, short int y0, short int r, unsigned char cornername,
		short int delta, unsigned short int color),
		drawTriangle(short int x0, short int y0, short int x1, short int y1,
		short int x2, short int y2, unsigned short int color),
		fillTriangle(short int x0, short int y0, short int x1, short int y1,
		short int x2, short int y2, unsigned short int color),
		drawRoundRect(short int x0, short int y0, short int w, short int h,
		short int radius, unsigned short int color),
		fillRoundRect(short int x0, short int y0, short int w, short int h,
		short int radius, unsigned short int color),
		drawBitmap(short int x, short int y, const unsigned char bitmap[],
		short int w, short int h, unsigned short int color),
		drawBitmap(short int x, short int y, const unsigned char bitmap[],
		short int w, short int h, unsigned short int color, unsigned short int bg),
		drawBitmap(short int x, short int y, unsigned char *bitmap,
		short int w, short int h, unsigned short int color),
		drawBitmap(short int x, short int y, unsigned char *bitmap,
		short int w, short int h, unsigned short int color, unsigned short int bg),
		drawXBitmap(short int x, short int y, const unsigned char bitmap[],
		short int w, short int h, unsigned short int color),
		drawGrayscaleBitmap(short int x, short int y, const unsigned char bitmap[],
		short int w, short int h),
		drawGrayscaleBitmap(short int x, short int y, unsigned char *bitmap,
		short int w, short int h),
		drawGrayscaleBitmap(short int x, short int y,
		const unsigned char bitmap[], const unsigned char mask[],
		short int w, short int h),
		drawGrayscaleBitmap(short int x, short int y,
		unsigned char *bitmap, unsigned char *mask, short int w, short int h),
		drawRGBBitmap(short int x, short int y, const unsigned short int bitmap[],
		short int w, short int h),
		drawRGBBitmap(short int x, short int y, unsigned short int *bitmap,
		short int w, short int h),
		drawRGBBitmap(short int x, short int y,
		const unsigned short int bitmap[], const unsigned char mask[],
		short int w, short int h),
		drawRGBBitmap(short int x, short int y,
		unsigned short int *bitmap, unsigned char *mask, short int w, short int h),
		drawChar(short int x, short int y, unsigned char c, unsigned short int color,
		unsigned short int bg, unsigned char size),
		setCursor(short int x, short int y),
		setTextColor(unsigned short int c),
		setTextColor(unsigned short int c, unsigned short int bg),
		setTextSize(unsigned char s),
		setTextWrap(bool w),
		cp437(bool x = true),
		setFont(const GFXfont *f = NULL),
		getTextBounds(char *string, short int x, short int y,
		short int *x1, short int *y1, unsigned short int *w, unsigned short int *h),
		getTextBounds(const __FlashStringHelper *s, short int x, short int y,
		short int *x1, short int *y1, unsigned short int *w, unsigned short int *h);

#if ARDUINO >= 100
	virtual size_t write(unsigned char);
#else
	virtual void   write(unsigned char);
#endif

	short int height(void) const;
	short int width(void) const;

	unsigned char getRotation(void) const;

	// get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
	short int getCursorX(void) const;
	short int getCursorY(void) const;

protected:
	void
		charBounds(char c, short int *x, short int *y,
		short int *minx, short int *miny, short int *maxx, short int *maxy);
	const short int	WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
	short int	_width, _height, // Display w/h as modified by current rotation
		cursor_x, cursor_y;
	unsigned short int textcolor, textbgcolor;
	unsigned char
		textsize,
		rotation;
	bool
		wrap,   // If set, 'wrap' text at right edge of display
		_cp437; // If set, use correct CP437 charset (default is off)
	GFXfont
		*gfxFont;
};

class DisplayDriver_Button {

public:
	DisplayDriver_Button(void);
	// "Classic" initButton() uses center & size
	void initButton(DisplayDriver *gfx, short int x, short int y,
		unsigned short int w, unsigned short int h, unsigned short int outline, unsigned short int fill,
		unsigned short int textcolor, char *label, unsigned char textsize);
	// New/alt initButton() uses upper-left corner & size
	void initButtonUL(DisplayDriver *gfx, short int x1, short int y1,
		unsigned short int w, unsigned short int h, unsigned short int outline, unsigned short int fill,
		unsigned short int textcolor, char *label, unsigned char textsize);
	void drawButton(bool inverted = false);
	bool contains(short int x, short int y);

	void press(bool p);
	bool isPressed();
	bool justPressed();
	bool justReleased();

private:
	DisplayDriver *_gfx;
	short int       _x1, _y1; // Coordinates of top-left corner
	unsigned short int      _w, _h;
	unsigned char       _textsize;
	unsigned short int      _outlinecolor, _fillcolor, _textcolor;
	char          _label[10];

	bool currstate, laststate;
};

class GFXcanvas1 : public DisplayDriver
{
public:
	GFXcanvas1(unsigned short int w, unsigned short int h);
	~GFXcanvas1(void);
	void     drawPixel(short int x, short int y, unsigned short int color),
		fillScreen(unsigned short int color);
	unsigned char *getBuffer(void);
private:
	unsigned char *buffer;
};

class GFXcanvas8 : public DisplayDriver
{
public:
	GFXcanvas8(unsigned short int w, unsigned short int h);
	~GFXcanvas8(void);
	void     drawPixel(short int x, short int y, unsigned short int color),
		fillScreen(unsigned short int color),
		writeFastHLine(short int x, short int y, short int w, unsigned short int color);

	unsigned char *getBuffer(void);
private:
	unsigned char *buffer;
};

class GFXcanvas16 : public DisplayDriver
{
public:
	GFXcanvas16(unsigned short int w, unsigned short int h);
	~GFXcanvas16(void);
	void      drawPixel(short int x, short int y, unsigned short int color),
		fillScreen(unsigned short int color);
	unsigned short int *getBuffer(void);
private:
	unsigned short int *buffer;
};

