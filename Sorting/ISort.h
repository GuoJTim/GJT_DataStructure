#include <vector>
#include <functional>
#include <algorithm>
#ifndef ISort_H
#define ISort_H 
#include <iostream>

// abstract class
template <class T,class U = std::less<T> >
class ISort{
	public:
		ISort();
		
		// basic sorting 
		virtual void Sort(std::vector<T> &arr) = 0;
		virtual void Sort() = 0;
		virtual void show_list(bool asLine = false) = 0;
		
};
#include "ISort.cpp"
#endif
