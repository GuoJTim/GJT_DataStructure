#ifndef CTimer_H
#define CTimer_H
#include <iostream>
#include <windows.h>
#include <stdlib.h>

class timer{
	public:
		static bool initial;
		static LARGE_INTEGER startTime, endTime, fre;
		static double time;
		static void init(){
			if (initial) return;
			QueryPerformanceFrequency(&timer::fre);
		}
		static void start_timer() {
			if (!initial) return;
			QueryPerformanceCounter(&startTime);
		}
		static void stop_timer() {
			if (!initial) return;
			QueryPerformanceCounter(&endTime);
			time = ((double)endTime.QuadPart - (double)startTime.QuadPart) /fre.QuadPart;
		}
		static std::string getFormat() {
			if (!initial) return " Please do init() first.";
			char tmp[100];
			sprintf(tmp, "this action spends about %f second(s).",(float)time);// string format
			std::string timeformat(tmp);
		return timeformat;
	}
};
LARGE_INTEGER timer::startTime;
LARGE_INTEGER timer::endTime;
LARGE_INTEGER timer::fre;
double timer::time = 0;
bool timer::initial = false;

#endif
