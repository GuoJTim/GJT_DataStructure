#include <vector>
#include <functional>
#include <algorithm>
#ifndef MergeSort_H
#define MergeSort_H 
template <class T,class U = std::less<T> >
class MergeSort{
	private:
		typedef U cmp; 	
		void mergesort(int p,int r);
		void merge(int p,int q,int r);
	public:
		std::vector<T> arr; // user using vector as input
		MergeSort(std::vector<T> &arr);
		void Sort(); // sorting driver
		void show_list(bool asLine = false);
};
#include "MergeSort.cpp"
#endif
