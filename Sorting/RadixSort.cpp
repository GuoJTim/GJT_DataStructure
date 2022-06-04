#include "RadixSort.h"
#include "CountingSort.h"

#include <iostream>
template <class T,class U>
RadixSort<T,U>::RadixSort(std::vector<T> &arr){
	this->arr = arr;
}

template <class T,class U>
RadixSort<T,U>::RadixSort(){
	
}


template <class T,class U>
void RadixSort<T,U>::LSD_Sort(){
	LSD_Sort(arr);
}

template <class T,class U>
void RadixSort<T,U>::LSD_Sort(std::vector<T> &arr){
	int MAX_INDEX = 10;
	for (int index = MAX_INDEX;index >= 0 ; index--){
		BucketSort<T> bs;
		auto func = [&](T obj) -> int{
			return ((int)obj / ((int)std::pow(10,MAX_INDEX-index)) ) % 10;
		};
		bs.Sort(arr,10,func);
	}
}

template <class T,class U>
void RadixSort<T,U>::MSD_Sort(int d){
	MSD_Sort(arr,0,arr.size()-1,d);
}

// 321 -> d = 2,1,0
template <class T,class U>
void RadixSort<T,U>::MSD_Sort(std::vector<T> &arr,int l,int r,int d){
	if (r <= l) return;
	if (d < 0) return;
	CountingSort<T> cs;
	cs.Sort(arr,l,r,d);
	cs.count.push_back(0);
	cs.count.push_back(0);
	for (int i = 0 ; i < 10 ; i++){
		MSD_Sort(arr,l+cs.count[i],l+cs.count[i+1]-1,d-1);
	}
}

template <class T,class U>
void RadixSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}