#include "InsertionSort.h"
#include <iostream>
template <class T,class U>
InsertionSort<T,U>::InsertionSort(std::vector<T> &arr,bool autoSort){
	if (!autoSort) this->arr = arr;
	else{
		for(T obj: arr){
			Insert(obj);
		}
	}
}
#include <iostream>
using namespace std;


template <class T,class U>
void InsertionSort<T,U>::Sort(){
	for (int j = 1 ; j < arr.size();j++){
		//if (j % 10000 == 0)cout << j << endl;
		T key = arr[j];
		int i = j - 1;
		while(i >= 0 && cmp()(key,arr[i])){
			arr[i+1] = arr[i];
			i = i - 1;
		}
		arr[i+1] = key;
	}
}

template <class T,class U>
void InsertionSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}

template <class T,class U>
void InsertionSort<T,U>::Insert(T key){
	int index = 0;
	for(; index < arr.size();index++){
		if (cmp()(key,arr[index])) break;
	}
	arr.insert(arr.begin() + index,key);  
}
