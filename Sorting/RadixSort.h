#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include "BucketSort.h"
#ifndef RadixSort_H
#define RadixSort_H 
//a linear sorting algorithm
template <class T,class U = std::less<T> >
class RadixSort{
	private:
		typedef U cmp; 	
		
	public:
		
		std::vector<T> arr; // user using vector as input
		RadixSort(std::vector<T> &arr);
		RadixSort();
		void LSD_Sort(std::vector<T> &arr); // sorting driver
		void LSD_Sort(); // inner vector sort
		void MSD_Sort(std::vector<T> &arr,int l,int r,int d); // sorting driver
		void MSD_Sort(int d); // inner vector sort
		void show_list(bool asLine = false);
		
};
#include "RadixSort.cpp"
#endif