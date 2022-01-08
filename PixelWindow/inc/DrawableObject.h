#pragma once
#include <complex>

class PixelManager;

class DrawableObject {
private:
protected: 
	static constexpr std::complex<int> _UP{ 0, -1 };
	static constexpr std::complex<int> _DWN{ 0, 1 };
	static constexpr std::complex<int> _RHT{ 1, 0 };
	static constexpr std::complex<int> _LFT{ -1, 0 };
	
	DrawableObject();
public:
	virtual void Draw(PixelManager& pxlm) = 0;
	bool shown;
	std::complex<int> location;

	void mvUp() {
		location += _UP;
	}
	void mvDown() {
		location += _DWN;
	}
	void mvLeft() {
		location += _LFT;
	}
	void mvRight() {
		location += _RHT;
	}
};