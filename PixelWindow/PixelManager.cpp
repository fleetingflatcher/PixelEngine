#include "inc/PixelManager.h"

/*
 *	Custom Math function namespace
 */
namespace Maths {
	// Lerp function could be made more efficent, but slightly 
	// incomplete by not calculating delta for each lerp
	float Lerp1D(int a, int b, float t) {
		short delta = b - a;
		return (a + (t * delta));
	}
}

/*
 *	Constructor Definition
 */
PixelManager::PixelManager(PixelWindow& windowReference, int w, int h, Color bgColor)
	: pixelWindow(windowReference), 
	backgroundColor(bgColor), 
	drawColor(Paint::White)
{
	pixels.resize(w);
	for (int i = 0; i < w; i++) {
		pixels[i].resize(h);
	}
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			pixels[i][j] = { i, j };
		}
};
Pixel PixelManager::GetPixel(int x, int y) {
	return pixels[x][y];
}


/*
 *	Public Function Definitions
 */
void PixelManager::SetDrawColor(const Color c) {
	drawColor = c;
}

void PixelManager::DrawPixel(Pixel* p) {
	if (p != nullptr) p->color = drawColor;
}
void PixelManager::DrawPixel(Pixel* p, Color newColor) {
	if (p != nullptr) p->color = newColor;
}
void PixelManager::DrawPixel(std::complex<int> loc) {
	DrawPixel(loc.real(), loc.imag());
}
void PixelManager::DrawPixel(std::complex<int> loc, Color newColor) {
	DrawPixel(loc.real(), loc.imag(), newColor);
}
void PixelManager::DrawPixel(int x, int y) {
	if (x < pixels.size() && y < pixels[x].size()) pixels[x][y].color = drawColor;
}
void PixelManager::DrawPixel(int x, int y, Color newColor) {
	if (x < pixels.size() && y < pixels[x].size()) pixels[x][y].color = newColor;
}

/*
 *	12/27/2021 NON-IDEAL CODE BELOW; optimization needed.
 *	Pixel pointers are converted to int 
 *	coordinates and then back to a pixel pointer.
 *	Waste of resources
 */
void PixelManager::DrawLine(Pixel* start, Pixel* fin) {
	int X_start, X_fin, Y_start, Y_fin;
	X_start = start->x, Y_start = start->y;
	X_fin = fin->x, Y_fin = fin->y;
	DrawLine(X_start, Y_start, X_fin, Y_fin, drawColor);
}
void PixelManager::DrawLine(Pixel* start, Pixel* fin, Color newColor) {
	int X_start, X_fin, Y_start, Y_fin;
	X_start = start->x, Y_start = start->y;
	X_fin = fin->x, Y_fin = fin->y;
	DrawLine(X_start, Y_start, X_fin, Y_fin, drawColor);
}

void PixelManager::DrawLine(int X_start, int Y_start, int X_fin, int Y_fin) {
	DrawLine(X_start, Y_start, X_fin, Y_fin, drawColor);
}
void PixelManager::DrawLine(int X_start, int Y_start, int X_fin, int Y_fin, Color newColor) {
	float t; int x, y; int n = 0;
	for (int i = 0; i < LINE_RESOLUTION; i++) {
		t = ((float)n / LINE_RESOLUTION);
		x = (int)round(Maths::Lerp1D(X_start, X_fin, t));
		y = (int)round(Maths::Lerp1D(Y_start, Y_fin, t));
		DrawPixel(&pixels[x][y], newColor);
		n++;
	}
}

void PixelManager::ResetScreen() {
	SetDrawColor(backgroundColor);
	for (int i = 0; i < pixelWindow.getNumX(); i++)
		for (int j = 0; j < pixelWindow.getNumY(); j++)
			DrawPixel(&pixels[i][j]);
}

/*
 *	Object Management Function definitions
 */
void PixelManager::AddObject(DrawableObject* o)
{
	objectList.push_back(o);
}
void PixelManager::DrawObjects() {
	for (int i = 0; i != objectList.size(); ++i) {
		objectList[i]->Draw(*this);
	}
}
bool PixelManager::RemoveObject(DrawableObject* targetObject) {
	return false;
}