#include "GenericPixelWindow.h"
#include "GenericObject.h"



void GenericPixelWindow::MakeActive() 
{
	active = true;
	gObj = new GenericObject(6, 3);
	PXLM->AddObject(gObj);
	ActiveLoop();
	delete gObj;
}

void GenericPixelWindow::ActiveLoop() {
	while (active) {
		ProcessFrame();
		HandleEvents();
		SDLM_Delay(40);
	}
}

void GenericPixelWindow::ProcessFrame() { 
	PXLM->DrawObjects();
	SDLM->DrawScreen(); 
	PXLM->ResetScreen();
}

void GenericPixelWindow::HandleEvents() {
	SDL_PumpEvents();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_UP]) gObj->mvUp();
	if (keystate[SDL_SCANCODE_DOWN]) gObj->mvDown();
	if (keystate[SDL_SCANCODE_LEFT]) gObj->mvLeft();
	if (keystate[SDL_SCANCODE_RIGHT]) gObj->mvRight();
	while (SDL_PollEvent(&sdlEvent)) {
		if (sdlEvent.type == SDL_KEYDOWN) {
			if (sdlEvent.key.keysym.sym == SDLK_q) active = false;
		}
	}
}