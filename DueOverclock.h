/*
	File Name: DueOverclock.h
	File By: Alexandre Rouma
	
	Use this code at your own risk ! I will NOT be responsible if you break your arduino !!!
*/

#ifndef DueOverclock_h
#define DueOverclock_h

#include "Arduino.h"

#define DEFAULT_FRQ	84

class DueOverclockClass {
	public:
		void setCoreFrequency(int frq);
		void setCoreMultiplier(int mlt);
		int getCoreFrequency();
		int getCoreMultiplier();
		long delayToOC(long del);
		long delayFromOC(long del);
		void OCDelay(long del);
		void OCDelayMicroseconds(long del);
		long OCMillis();
		long OCMicros();

	private:
		int cpuMult = 13;
};

extern DueOverclockClass DueOverclock;

#endif