#include <SDL.h>

class Clock {
private:
	Uint32 tot;
	Uint32 prev;
	int del;
public:
	/*
	 Initialization starts all at NULL and ticks once.
	 
	 NOTE: This may result in abnormally high values for 
	 delta after first tick if the clock is started late.
	 */
	Clock() : tot(NULL), prev(NULL), del(NULL) {
		Tick();
	}
	void Tick()
	{
		tot = SDL_GetTicks();
		del = tot - prev;
		prev = SDL_GetTicks();
	}
	Uint32 getTickDelta() {
		return del;
	}
};

class Timer {
	static constexpr int tolerance = 33;
private:
	unsigned int current;
	const unsigned int length;
public: 
	Timer(int period) : length(period), current(NULL) {};
	/*
	Returns true if the timer has time left.
	*/
	bool IsOn() {
		return current; //&& current < length - tolerance;
	}
	/*
	Returns true if the timer is out of time.
	*/
	bool IsOff() {
		return !current;
	}
	/*
	Set the timer.
	*/
	void Set() {
		current = length;
	}
	/*
	Allow ms milliseconds to elapse on this timer.
	Returns true if timer expires due to this change.
	*/
	bool Elapse(int ms) {
		if (current > ms) current -= ms;
		else current = 0;
		return !current;
	}
};