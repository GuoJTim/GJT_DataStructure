#include "IntroSort.h"
#include <iostream>
template <class T,class U>
void IntroSort<T,U>::introsort(std::vector<T> &arr,int begin,int end,int depth){
	int size = end - begin;
	
	if(size < 16){
		InsertionSort<T,U> is;
		is.Sort(arr,begin,end);
		return;
	}
	
	if (depth == 0){
		HeapSort<T,U> hs;
		hs.Sort(arr,begin,end+1);
		return;
	}
	
	int p = MedianOfThree(arr,begin,begin+size/2,end);
	
	swap(arr[p],arr[end]);
	int q = Partition(arr,begin,end);
	introsort(arr,begin,q-1,depth-1);
	introsort(arr,q+1,end,depth-1);
	
}

template <class T,class U>
IntroSort<T,U>::IntroSort(std::vector<T> &arr){
	this->arr = arr;
}
template <class T,class U>
IntroSort<T,U>::IntroSort(){
}

template <class T,class U>
int IntroSort<T,U>::Partition(vector<T> &arr,int p,int r){
	T x = arr[r];
	int i = p-1;
	for(int j = p ; j < r;j++){
		if(cmp()(arr[j],x)|| arr[j] == x ){
			i = i+1;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}

template <class T,class U>
void IntroSort<T,U>::Sort(vector<T> &arr){
	int depthLimit = 2*floor(log(arr.size()-1));
	introsort(arr,0,arr.size()-1,depthLimit);
}
template <class T,class U>
void IntroSort<T,U>::Sort(){
	Sort(arr);
}

template <class T,class U>
int IntroSort<T,U>::MedianOfThree(vector<T> &arr,int p,int middle,int r){
	// a < b < c
	int pivot_index;
	if ((arr[p] < arr[middle] || arr[p] == arr[middle]) && (arr[middle] < arr[r] || arr[middle] == arr[r])) pivot_index = middle;
	if ((arr[r] < arr[middle] || arr[r] == arr[middle]) && (arr[middle] < arr[p] || arr[middle] == arr[p])) pivot_index = middle;
	if ((arr[middle] < arr[p] || arr[middle] == arr[p]) && (arr[p] < arr[r] || arr[p] == arr[r])) pivot_index = p;
	if ((arr[r] < arr[p] || arr[r] == arr[p]) && (arr[p] < arr[middle] || arr[p] == arr[middle])) pivot_index = p;
	if ((arr[middle] < arr[r] || arr[middle] == arr[r]) && (arr[r] < arr[p] || arr[r] == arr[p])) pivot_index = r;
	if ((arr[p] < arr[r] || arr[p] == arr[r]) && (arr[r] < arr[middle] || arr[r] == arr[middle])) pivot_index = r;
	return pivot_index;
}

template <class T,class U>
void IntroSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}
