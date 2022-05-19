#include <vector>
#include <functional>
#include <algorithm>
#ifndef MergeSort_H
#define MergeSort_H 
template <class T,class U = std::less<T> >
class MergeSort{
	private:
		typedef U cmp; 	
		void mergesort(std::vector<T> &arr,int p,int r);
		void merge(std::vector<T> &arr,int p,int q,int r);
	public:
		std::vector<T> arr; // user using vector as input
		MergeSort(std::vector<T> &arr);
		MergeSort();
		void Sort(); // inner sort
		void Sort(std::vector<T> &arr); // sorting driver
		void show_list(bool asLine = false);
};
#include "MergeSort.cpp"
#endif
