#include "../PixelWindow/inc/DrawableObject.h"
#include "../PixelWindow/inc/PixelManager.h"
#include <vector>

using namespace std;

class GenericObject : public DrawableObject {
public:
	GenericObject(int x, int y) {
		location = {x, y};
	}
	virtual void Draw(PixelManager& pxlm) override {
		pxlm.SetDrawColor(Paint::White);
		pxlm.DrawPixel(location);
	}
};