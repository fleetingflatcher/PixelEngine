#pragma once
#include <complex>

class PixelManager;

namespace Compass {
	using namespace std;
	constexpr complex<int> Null{ 0, 0 };
	constexpr complex<int> Up{ 0, -1 };
	constexpr complex<int> Dwn{ 0, 1 };
	constexpr complex<int> Lft{ -1, 0 };
	constexpr complex<int> Rht{ 1, 0 };
};

class DrawableObject {
private:
protected: 
	DrawableObject();
public:
	virtual void Draw(PixelManager& pxlm) = 0;
	bool shown;
	std::complex<int> location;

	std::complex<int> mvDirection;
	void mv() {
		location += mvDirection;
	}
	void mvUp() {
		location += Compass::Up;
	}
	void mvDown() {
		location += Compass::Dwn;
	}
	void mvLeft() {
		location += Compass::Lft;
	}
	void mvRight() {
		location += Compass::Rht;
	}
};