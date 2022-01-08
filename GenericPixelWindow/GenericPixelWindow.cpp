#include "GenericPixelWindow.h"
#include "GenericObject.h"



void GenericPixelWindow::MakeActive() 
{
	active = true;
	gObj = new GenericObject(3, 3);
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
}

void GenericPixelWindow::HandleEvents() {
	if (SDL_PollEvent(&sdlEvent)) {
		if (sdlEvent.type == SDL_KEYDOWN) {
			if (sdlEvent.key.keysym.sym == SDLK_q) active = false;
			if (sdlEvent.key.keysym.sym == SDLK_UP) gObj->mvUp();
			if (sdlEvent.key.keysym.sym == SDLK_DOWN) gObj->mvDown();
			if (sdlEvent.key.keysym.sym == SDLK_LEFT) gObj->mvLeft();
			if (sdlEvent.key.keysym.sym == SDLK_RIGHT) gObj->mvRight();
		}
	}
}