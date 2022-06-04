#include <vector>
#include <functional>
#include <algorithm>
#ifndef QuickSort_H
#define QuickSort_H 
// quick sort is an in-place algorithm
// so that using the ordinary array as inner member array
template <class T,class U = std::less<T> >
class QuickSort{
	private:
		typedef U cmp; 	
		void quicksort(std::vector<T> &arr,int p,int r,int(*partition)(std::vector<T> &,int,int) = nullptr); //recursive sort
		void quicksortWithMedianOfThree(std::vector<T> &arr,int p,int r); //recursive sort
		int Partition(std::vector<T> &arr,int p,int r); // partition
		int MedianOfThree(std::vector<T> &arr,int p,int r);
	public:
		
		std::vector<T> arr; // user using vector as input
		QuickSort(std::vector<T> &arr);
		QuickSort();
		void Sort(std::vector<T> &arr,int(*partition)(std::vector<T> &,int,int) = nullptr); // sorting driver
		void Sort(int(*partition)(std::vector<T> &,int,int) = nullptr); // inner vector sort
		void SortWithMedianOfThree(std::vector<T> &arr); // sorting driver
		void SortWithMedianOfThree(); // sorting driver
		void show_list(bool asLine = false);
		
};
#include "QuickSort.cpp"
#endif