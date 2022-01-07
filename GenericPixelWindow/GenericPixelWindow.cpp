#include "GenericPixelWindow.h"
#include "GenericObject.h"

void GenericPixelWindow::MakeActive() 
{
	active = true;
	DrawableObject* gObj = new GenericObject(3, 3);
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
	PXLM->DrawPixel(1, 1, Paint::White);
	SDLM->DrawScreen(); 
}

void GenericPixelWindow::HandleEvents() {
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_q) active = false;
		}
	}
}