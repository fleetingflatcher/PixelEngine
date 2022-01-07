#pragma once
#include "Pixel.h"
#include "PixelManager.h"
#include <complex>

class DrawableObject {
private:
protected: 
	DrawableObject();
public:
	virtual void Draw(PixelManager& pxlm) = 0;
	bool shown;
	std::complex<int> location;
};