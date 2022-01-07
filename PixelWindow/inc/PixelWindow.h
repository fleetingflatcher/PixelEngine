#pragma once
#include "Pixel.h"
#include "Color.hpp"
#include <vector>
#include <SDL.h>
#include "PixelManager.h"
#include "SDLManager.h"


using namespace std;

class PixelWindow {

//	Virtual functions, to be overriden by derived classes
public:
	virtual void MakeActive() = 0;
protected:
	virtual void ActiveLoop() = 0;
	virtual void ProcessFrame() = 0;
	virtual void HandleEvents() = 0;

//	Private & Protected Data Member declarations
private:
	int PIXEL_SIZE;
	int NUM_PIXELS_X;
	int NUM_PIXELS_Y;

protected:
	bool active;
	SDL_Event event;

//	Public Data Member declarations
public:
	SDLManager* SDLM;
	PixelManager* PXLM;

//	Private Method declarations
private:

//	Public Method declarations
public:
	// Delegating Constructors
	PixelWindow(int px_size, int num_x, int num_y)
		: PixelWindow(px_size, num_x, num_y, false, Paint::Black) {};
	PixelWindow(int px_size, int num_x, int num_y, bool grid)
		: PixelWindow(px_size, num_x, num_y, grid, Paint::Black) {};
	PixelWindow(int px_size, int num_x, int num_y, Color bgColor)
		: PixelWindow(px_size, num_x, num_y, false, bgColor) {};
	// Primary Constructor & Destructor
	PixelWindow(int px_size, int num_x, int num_y, bool grid = false, Color bgColor = Paint::Black);
	~PixelWindow();

	// Pixel Information Retrieval Methods
	int getPixelSize();
	int getNumX();
	int getNumY();
};