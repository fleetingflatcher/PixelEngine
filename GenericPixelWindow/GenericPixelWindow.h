#pragma once
#include "../PixelWindow/inc/PixelWindow.h"

class GenericPixelWindow : public PixelWindow {
private:
	static constexpr int MV_DELAY = 335;
	Timer mvTimer { MV_DELAY };
	DrawableObject* gObj;
public:
	using PixelWindow::PixelWindow;
	virtual void MakeActive();
protected:
	virtual void ActiveLoop();
	virtual void HandleEvents();
	virtual void ProcessFrame();
};