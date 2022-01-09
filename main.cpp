//#include "Snake/snake.h"
#include "PixelWindow/inc/PixelWindow.h"
#include "GenericPixelWindow/GenericPixelWindow.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[]) {
	bool programRunning = true;
	cout << "Testing... 1, 2, 3...\n" << endl;

	cout << "Creating PixelWindow.\n" << endl;
	
	GenericPixelWindow* PXW = new GenericPixelWindow(45, 9, 9, true);
	PXW->MakeActive();
	
	delete PXW;
	return 0;
}