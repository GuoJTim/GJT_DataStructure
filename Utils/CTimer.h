#ifndef CTimer_H
#define CTimer_H
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <functional>

class CTimer{
	public:
		static bool initial;
		static LARGE_INTEGER startTime, endTime, fre;
		static double time;
		static void init(){
			if (initial) return;
			QueryPerformanceFrequency(&CTimer::fre);
			initial = true;
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
		static std::string getFormat(std::string s) {
			if (!initial) return " Please do init() first.";
			char tmp[100];
			sprintf(tmp, s.c_str(),(float)time);// string format
			std::string timeformat(tmp);
			return timeformat;
		}
		static void calc(std::function<void()> func){
			if (!initial) init();
			start_timer();
			func();
			stop_timer();
			std::cout << getFormat() << std::endl;
		}
		static void calc(std::function<void()> func,std::string format){
			if (!initial) init();
			start_timer();
			func();
			stop_timer();
			std::cout << getFormat(format);
		}
	
};
LARGE_INTEGER CTimer::startTime;
LARGE_INTEGER CTimer::endTime;
LARGE_INTEGER CTimer::fre;
double CTimer::time = 0;
bool CTimer::initial = false;

#endif
