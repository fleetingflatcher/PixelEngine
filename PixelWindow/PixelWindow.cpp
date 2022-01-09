#include "inc/PixelWindow.h"


/*
 *	PixelWindow Class method definitions
 */
//	PROTECTED METHODS



//	PUBLIC METHODS
// All other constructors delegate to the below universal constructor.
PixelWindow::PixelWindow(int px_size, int num_x, int num_y, bool grid, Color bgColor) :
	clock(),
	active(true),
	PIXEL_SIZE(px_size),
	NUM_PIXELS_X(num_x),
	NUM_PIXELS_Y(num_y),
	PXLM(new PixelManager(*this, num_x, num_y, bgColor)),
	SDLM(new SDLManager(*this, num_x, num_y, px_size, grid))
{
	SDL_PollEvent(&sdlEvent);
	SDLM->Start(grid);
};
PixelWindow::~PixelWindow()
{
	delete PXLM;
	SDLM->Quit();
	delete SDLM;
};
int PixelWindow::getPixelSize() {
	return PIXEL_SIZE;
};
int PixelWindow::getNumX() {
	return NUM_PIXELS_X;
};
int PixelWindow::getNumY() {
	return NUM_PIXELS_Y;
}