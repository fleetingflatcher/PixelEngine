#include "inc/SDLManager.h"

// Private method definitions
void SDLManager::InitError(const char* item) {
	printf("[ERROR]: Failed to initialize %s!\nSDL Error: %s\n", item, SDL_GetError());
}
void SDLManager::DrawRectFromPixel(Pixel p) {
	SDL_SetRenderDrawColor(renderer, p.color.red(), p.color.green(), p.color.blue(), 0xFF);
	//SDL_SetRenderDrawColor(renderer, 0xDD, 0xDD, 0xDD, 0xFF);
	SDL_RenderFillRect(renderer, &(rects[p.x][p.y]));
}
void SDLManager::DrawGridlines() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (int i = 0; i < pixelWindow.getNumX(); i++)
		for (int j = 0; j < pixelWindow.getNumY(); j++) {
			SDL_RenderDrawRect(renderer, &rects[i][j]);
		}
}

// Public method definitions
//SDL Initialization function
SDLManager::SDLManager(PixelWindow& windowReference, 
	int w, int h, int sz, bool gridBool) :
	window(NULL),
	renderer(NULL),
	gridlineFlag(gridBool),
	WINDOW_SIZE_X(pixelWindow.getNumX()* pixelWindow.getPixelSize()),
	WINDOW_SIZE_Y(pixelWindow.getNumY()* pixelWindow.getPixelSize()),
	pixelWindow(windowReference) 
{
	rects.resize(w);
	for (int i = 0; i < w; i++) {
		rects[i].resize(h);
	}
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			rects[i][j] = { i * sz, j * sz, sz, sz };
		}
}

bool SDLManager::Start(bool grid, Color bgColor) {
	bool successFlag = true;

	if (SDL_Init(SDL_INIT_EVERYTHING < 0)) {
		InitError("SDL");
		successFlag = false;
	}
	else {
		window = SDL_CreateWindow(SDL_WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_SIZE_X, WINDOW_SIZE_Y,
			SDL_WINDOW_SHOWN);
		if (window == NULL) {
			InitError("WINDOW");
			successFlag = false;
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				InitError("RENDERER");
				successFlag = false;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
		if (grid) gridlineFlag = true;
		SDL_RenderPresent(renderer);
	}
	return successFlag;
}
void SDLManager::Quit() {
	SDL_Quit();
}

void SDLManager::DrawScreen() {
	SDL_RenderClear(renderer);
	for (int i = 0; 
		i < pixelWindow.getNumX(); 
		i++)
		for (int j = 0; j < pixelWindow.getNumY(); j++) {
			DrawRectFromPixel(pixelWindow.PXLM->GetPixel(i,j));
		}
	if (gridlineFlag) DrawGridlines();
	SDL_RenderPresent(renderer);
}