#include <vector>
#include <functional>
#include <algorithm>
#ifndef IntroSort_H
#define IntroSort_H 
#include "InsertionSort.h"
#include "HeapSort.h"

template <class T,class U = std::less<T> >
class IntroSort{
	private:
		typedef U cmp; 	
		int Partition(std::vector<T> &arr,int p,int r); // partition
		int MedianOfThree(std::vector<T> &arr,int p,int middle,int r);
		void introsort(std::vector<T> &arr,int begin,int end,int depth);
	public:
		std::vector<T> arr; // user using vector as input
		IntroSort(std::vector<T> &arr);
		IntroSort();
		void Sort(); // sorting driver
		void Sort(std::vector<T> &arr); // sorting driver
		void show_list(bool asLine = false);
		
};
#include "IntroSort.cpp"
#endif
