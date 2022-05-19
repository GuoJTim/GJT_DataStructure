#include <vector>
#include <functional>
#include <algorithm>
#ifndef InsertionSort_H
#define InsertionSort_H 
// insertion sort is an in-place algorithm
// so that using the ordinary array as inner member array
template <class T,class U = std::less<T> >
class InsertionSort{
	private:
		typedef U cmp; 	
		
	public:
		
		std::vector<T> arr; // user using vector as input
		InsertionSort();//without inner arr
		InsertionSort(std::vector<T> &arr,bool autoSort = false); // autoSort -> sort with inital  
		void Sort(std::vector<T> &arr); // sorting
		void Sort(std::vector<T> &arr,int begin,int end); // sorting
		void Sort(); // sorting
		void show_list(bool asLine = false);
		void Insert(T key); // insert new element
		
};
#include "InsertionSort.cpp"
#endif
