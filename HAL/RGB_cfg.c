#include "RGB.h"


/*  array of pointers to constant characters
    or in simpler terms, an array of strings  */
const u8 *color_names[] =
{
	"Red",
	"Green",
	"Blue",
	"Black",
	"Magenta",
	"Cyan",
	"Maroon",
	"Olive",
	"Navy",
	"Yellow-Green",
	"Purple",
	"Teal",
	"Gray",
	"Dark Gray",
	"White"
};

u16 colors[][3] =
{
	{255, 0, 0},      // Red
	{0, 255, 0},      // Green
	{0, 0, 255},      // Blue
	{0, 0, 0},        // Black
	{255, 0, 255},    // Magenta
	{0, 255, 255},    // Cyan
	{128, 0, 0},      // Maroon
	{0, 128, 0},      // Olive
	{0, 0, 128},      // Navy
	{128, 128, 0},    // Yellow-Green
	{128, 0, 128},    // Purple
	{0, 128, 128},    // Teal
	{192, 192, 192},  // Gray
	{128, 128, 128},  // Dark Gray
	{255, 255, 255}   // White
};