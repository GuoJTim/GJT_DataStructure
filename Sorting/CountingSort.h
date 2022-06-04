#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#ifndef CountingSort_H
#define CountingSort_H 
//a linear sorting algorithm
template <class T,class U = std::less<T> >
class CountingSort{
	private:
		typedef U cmp; 	
		
	public:
		
		std::vector<T> arr; // user using vector as input
		std::vector<int> count; // user using vector as input
		CountingSort(std::vector<T> &arr);
		CountingSort();
		void Sort(std::vector<T> &arr,int index = 0); // sorting driver
		void Sort(std::vector<T> &arr,int st,int ed,int index = 0); // sorting driver
		void Sort(int index = 0); // inner vector sort
		void show_list(bool asLine = false);
		
};
#include "CountingSort.cpp"
#endif