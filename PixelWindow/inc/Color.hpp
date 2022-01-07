#pragma once

class Color {
public:
	int value;
	int red() {
		int i = value;
		char* pt = (char*)&i;
		return (int)pt[2];
	}
	int green() {
		int i = value;
		char* pt = (char*)&i;
		return (int)pt[1];
	}
	int blue() {
		int i = value;
		char* pt = (char*)&i;
		return (int)pt[0];
	}
};

namespace Paint {
	const Color Black = { 0x000000 };
	const Color White = { 0xEEEEEE };
	const Color Red = { 0xEE0000 };
	const Color Green = { 0x00EE00 };
	const Color	Blue = { 0x0000EE };
}

/*
https://cplusplus.com/forum/general/48570/
You can use C/C++ various bitwise operators to do what you want. 
Or you may want to use C++ STL BitSet class instead. 
http://www.cplusplus.com/reference/stl/bitset/
You can do it with pointers. If you create a char pointer, and 
give it the value of the address of the int, you can then
use pointer arithmetic to move the char pointer along the int as 
you wish. Since a char is one byte long, you can then use that 
pointer to read single byte values.
*/