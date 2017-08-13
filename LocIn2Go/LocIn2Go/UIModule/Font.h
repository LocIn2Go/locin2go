#ifndef FONT_H_
#define FONT_H_

typedef struct 
{ // Data stored PER GLYPH
	unsigned short int bitmapOffset;	// Pointer into GFXfont->bitmap
	unsigned char  width, height;		// Bitmap dimensions in pixels
	unsigned char  xAdvance;			// Distance to advance cursor (x axis)
	int8_t   xOffset, yOffset;			// Dist from cursor pos to UL corner
} Glyph;

typedef struct 
{ // Data stored for FONT AS A WHOLE:
	unsigned char  *bitmap;			// Glyph bitmaps, concatenated
	Glyph *glyph;					// Glyph array
	unsigned char   first, last;	// ASCII extents
	unsigned char   yAdvance;		// Newline distance (y axis)
} Font;

#endif // FONT_H_