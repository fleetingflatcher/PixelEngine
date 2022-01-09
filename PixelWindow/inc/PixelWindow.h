#pragma once
#include "Pixel.h"
#include "Tickers.hpp"
#include "Color.hpp"
#include <vector>
#include <SDL.h>
#include "PixelManager.h"
#include "SDLManager.h"

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
	Clock clock;
	SDL_Event sdlEvent;

//	Public Data Member declarations
public:
	SDLManager* SDLM;
	PixelManager* PXLM;

//	Inheritable-Private Method declarations
protected:
	

//	Public Method declarations
public:
	// Primary Constructor & Destructor
	PixelWindow(int px_size, int num_x, int num_y, bool grid = false, Color bgColor = Paint::Black);
	~PixelWindow();

	// Pixel Information Retrieval Methods
	int getPixelSize();
	int getNumX();
	int getNumY();
};