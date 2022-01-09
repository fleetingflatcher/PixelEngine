#include "GenericPixelWindow.h"
#include "GenericObject.h"


void GenericPixelWindow::MakeActive() 
{
	active = true;
	gObj = new GenericObject(2, 3);
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
	clock.Tick();
	std::complex<int>& direction = gObj->mvDirection;
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_UP]) {
		direction = Compass::Up;
	}
	else if (keystate[SDL_SCANCODE_DOWN]) {
		direction = Compass::Dwn;
	}
	else if (keystate[SDL_SCANCODE_LEFT]) {
		direction = Compass::Lft;
	}
	else if (keystate[SDL_SCANCODE_RIGHT]) {
		direction = Compass::Rht;
	}
	while (SDL_PollEvent(&sdlEvent)) {
		if (sdlEvent.type == SDL_KEYDOWN) {
			if (sdlEvent.key.keysym.sym == SDLK_q) 
				active = false;
		}
	}
	SDL_PumpEvents();
	if (mvTimer.IsOff()) {
		bool mv = true;
		if (direction == Compass::Null) 
			mv = false;
		else {
			gObj->mv();
			mvTimer.Set();
			direction = Compass::Null;
		}
	}
	else {
		mvTimer.Elapse(clock.getTickDelta());
	}
	
}