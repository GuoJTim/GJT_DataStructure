#include "BucketSort.h"
#include <iostream>
template <class T,class U>
BucketSort<T,U>::BucketSort(std::vector<T> &arr){
	this->arr = arr;
}

template <class T,class U>
BucketSort<T,U>::BucketSort(){
	
}


template <class T,class U>
void BucketSort<T,U>::Sort(int n,int(*partition)(T)){
	Sort(arr,n,partition);
}

template <class T,class U>
void BucketSort<T,U>::Sort(int n,std::function<int(T)> func){
	Sort(arr,n,func);
}


template <class T,class U>
void BucketSort<T,U>::Sort(std::vector<T> &arr,int n,std::function<int(T)> partition){
	std::vector<std::vector<T>> bucket(n);
	for (int i = 0 ; i < arr.size() ; i++){
		bucket[partition(arr[i])].push_back(arr[i]);
	}
	
	//sorting each bucket
	for (int i = 0 ; i < n ; i++){
		sort(bucket[i].begin(),bucket[i].end());
	}
	
	int index = 0;
	//replace to original arr
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < bucket[i].size();j++){
			arr[index++] = bucket[i][j];
		}
	}
}


// n regard as the number of buckets
template <class T,class U>
void BucketSort<T,U>::Sort(std::vector<T> &arr,int n,int(*partition)(T)){
	if (partition == nullptr && n != arr.size()){
		n = arr.size(); // basic bucket sort with range 0.0-1.0
	}
	std::vector<std::vector<T>> bucket(n);
	for (int i = 0 ; i < arr.size() ; i++){
		if (partition == nullptr){
			bucket[(int)(arr[i] * n)].push_back(arr[i]);
		}else{
			bucket[(*partition)(arr[i])].push_back(arr[i]);
		}
	}
	
	//sorting each bucket
	for (int i = 0 ; i < n ; i++){
		sort(bucket[i].begin(),bucket[i].end());
	}
	
	int index = 0;
	//replace to original arr
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < bucket[i].size();j++){
			arr[index++] = bucket[i][j];
		}
	}
	
	
}

template <class T,class U>
void BucketSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}