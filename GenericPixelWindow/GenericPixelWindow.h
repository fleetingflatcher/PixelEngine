#pragma once
#include "../PixelWindow/inc/PixelWindow.h"

class GenericPixelWindow : public PixelWindow {
private:
	int frameNum;
public:
	using PixelWindow::PixelWindow;
	virtual void MakeActive();
protected:
	virtual void ActiveLoop();
	virtual void HandleEvents();
	virtual void ProcessFrame();
};