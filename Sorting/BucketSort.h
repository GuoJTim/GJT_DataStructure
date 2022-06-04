#include <vector>
#include <functional>
#include <algorithm>
#ifndef BucketSort_H
#define BucketSort_H 
//a linear sorting algorithm
template <class T,class U = std::less<T> >
class BucketSort{
	private:
		typedef U cmp; 	
		
	public:
		
		std::vector<T> arr; // user using vector as input
		BucketSort(std::vector<T> &arr);
		BucketSort();
		// partiton 為分割 bucket 的方式 (輸入為 T obj) 輸出為 所在的index
		void Sort(std::vector<T> &arr,int n,int(*partition)(T) = nullptr); // sorting driver
		void Sort(std::vector<T> &arr,int n,std::function<int(T)> func); 
		void Sort(int n,int(*partition)(T) = nullptr); // inner vector sort
		void Sort(int n,std::function<int(T)> func); 
		void show_list(bool asLine = false);
		
};
#include "BucketSort.cpp"
#endif