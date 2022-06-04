#include "CountingSort.h"
#include <iostream>


template <class T,class U>
CountingSort<T,U>::CountingSort(std::vector<T> &arr){
	this->arr = arr;
}

template <class T,class U>
CountingSort<T,U>::CountingSort(){
	
}


template <class T,class U>
void CountingSort<T,U>::Sort(int index){
	Sort(arr,index);
}

template <class T,class U>
void CountingSort<T,U>::Sort(std::vector<T> &arr,int index){
	std::vector<T> cp(arr);
	std::vector<int> cc(10);
	for (int i = 0 ; i < arr.size();i++){
		int digit = cp[i] / (int)pow(10,index);
		digit %= 10;
		cc[digit]++;
	}
	
	
	count = std::vector<int>(cc);
	
	for (int i = 1 ; i < cc.size();i++){
		cc[i] = cc[i] + cc[i-1];
	}
	for (int i = arr.size()-1 ; i>= 0 ; i--){
		int digit = cp[i] / (int)pow(10,index);
		digit %= 10;
		arr[cc[digit]-1] = cp[i];
		cc[digit]--;  
	}
}

template <class T,class U>
void CountingSort<T,U>::Sort(std::vector<T> &arr,int st,int ed,int index){
	std::vector<T> cp(ed-st+1); // [st,ed] = ed-st + 1
	int digit = (int)pow(10,index);
	std::vector<int> cc(10);
	for (int i = st ; i <= ed;i++){
		cp[i-st] = arr[i]; // copy value
		int digit = arr[i] / (int)pow(10,index);
		digit %= 10;
		cc[digit]++;
	}
	count = std::vector<int>(cc);
	
	for (int i = 1 ; i < cc.size();i++){
		cc[i] = cc[i] + cc[i-1];
	}
	for (int i = ed ; i>= st ; i--){
		int digit = cp[i-st] / (int)pow(10,index);
		digit %= 10;
		arr[st+cc[digit]-1] = cp[i-st];
		cc[digit]--;  
	}
}

template <class T,class U>
void CountingSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}