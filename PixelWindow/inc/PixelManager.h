#pragma once

#include <vector>
#include <complex>
#include <math.h>

#include "Pixel.h"
#include "Color.hpp"
#include "DrawableObject.h"

class PixelWindow;

class PixelManager {

private:
	// Parent reference
	PixelWindow& pixelWindow;
	std::vector<std::vector<Pixel>> pixels;
	std::vector<DrawableObject*> objectList;

	int LINE_RESOLUTION = 10;
	int CIRCLE_RESOLUTION = 12;

	Color backgroundColor;
	Color drawColor;

//	Public data members		
public:
	PixelManager(PixelWindow&, int, int, Color);
	Pixel GetPixel(int, int);

//	Public functions
	void AddObject(DrawableObject*);
	void DrawObjects();
	bool RemoveObject(DrawableObject*);

	void SetDrawColor(const Color);
	void ResetScreen();

	void DrawPixel(Pixel*);
	void DrawPixel(Pixel*, Color);
	void DrawPixel(std::complex<int>);
	void DrawPixel(std::complex<int>, Color);
	void DrawPixel(int, int);
	void DrawPixel(int, int, Color);

	void DrawLine(Pixel*, Pixel*);
	void DrawLine(Pixel*, Pixel*, Color);
	void DrawLine(int, int, int, int);
	void DrawLine(int, int, int, int, Color);

	void DrawCircle(Pixel center, float radius);
	void DrawCircle(int x, int y, float radius);
};

#include "PixelWindow.h"