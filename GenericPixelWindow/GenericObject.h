#include "../PixelWindow/inc/DrawableObject.h"
#include "../PixelWindow/inc/PixelManager.h"
#include <complex>




class GenericObject : public DrawableObject {
private:
	
public:
	GenericObject(int x, int y) {
		location = {x, y};
	}
	virtual void Draw(PixelManager& pxlm) {
		pxlm.SetDrawColor(Paint::White);
		pxlm.DrawPixel(location);
	}

};