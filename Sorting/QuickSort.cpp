#include "QuickSort.h"
#include <iostream>
template <class T,class U>
void QuickSort<T,U>::quicksort(int p,int r,int(*partfunc)(std::vector<T> &,int,int)){
	if(p < r){
		int q;
		if (partfunc == nullptr) q = Partition(p,r); //initial pivot choose function
		else q = (*partfunc)(arr,p,r);
		quicksort(p,q-1);
		quicksort(q+1,r);
	}
}

template <class T,class U>
void QuickSort<T,U>::quicksortWithMedianOfThree(int p,int r){
	if(p < r){
		int q;
		int m = MedianOfThree(p,r);
		std::swap(arr[m],arr[p]);
		q = Partition(p,r); 
		quicksort(p,q-1);
		quicksort(q+1,r);
	}
}

template <class T,class U>
QuickSort<T,U>::QuickSort(std::vector<T> &arr){
	this->arr = arr;
}

template <class T,class U>
int QuickSort<T,U>::Partition(int p,int r){
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
void QuickSort<T,U>::Sort(int(*partition)(std::vector<T> &,int,int)){
	quicksort(0,arr.size()-1,partition);
}

template <class T,class U>
void QuickSort<T,U>::SortWithMedianOfThree(){
	quicksortWithMedianOfThree(0,arr.size()-1);
}

template <class T,class U>
int QuickSort<T,U>::MedianOfThree(int p,int r){
	int middle = (p+r) / 2;
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
void QuickSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}
