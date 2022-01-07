#pragma once
#define SDLM_Delay(ms) SDL_Delay(ms)

class SDLManager;
class PixelWindow;
struct Pixel;

#include "Color.hpp"
#include <SDL.h>
#include <stdio.h>
#include <vector>

class SDLManager {
	// Private data members
private:
	// Parent reference
	PixelWindow& pixelWindow;
	std::vector<std::vector<SDL_Rect>> rects;

	bool gridlineFlag = false;
	const char* SDL_WINDOW_TITLE = "PixelGrid";
	int WINDOW_SIZE_X;
	int WINDOW_SIZE_Y;
	SDL_Window* window;
	SDL_Renderer* renderer;


	// Private methods
private:
	void InitError(const char*);
	void DrawRectFromPixel(Pixel);
	void DrawGridlines();

	// Public methods
public:
	SDLManager(PixelWindow&, int, int, int, bool);
	bool Start(bool, Color);
	bool Start(bool);
	void DrawScreen();
	void Quit();
};

#include "PixelWindow.h"