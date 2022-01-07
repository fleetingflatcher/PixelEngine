//#include "Snake/snake.h"
#include "PixelWindow/inc/PixelWindow.h"
#include "GenericPixelWindow/GenericPixelWindow.h"
#include <conio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	bool programRunning = true;
	printf("Testing... 1, 2, 3...\n");

	printf("Creating PixelWindow.\n");
	
	GenericPixelWindow* PXW = new GenericPixelWindow(50, 5, 5, true);
	PXW->MakeActive();
	
	delete PXW;
	return 0;
}