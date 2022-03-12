#include "Heap.h"
#include "../Utils/TreeTextHelper.cpp"


#include <iostream>
template <class T>
Heap<T>::Heap(){
	this->type = MAX_HEAP;
}

template <class T>
Heap<T>::Heap(HeapType type){
	this->type = type;
	arr.resize(1);
}
template <class T>
Heap<T>::Heap(HeapType type,vector<T> arr){
	this->type = type;
	for(T data: arr) Insert(data);
}

template <class T>
void Heap<T>::Insert(T data){
	arr.push_back(data);
	int current_index = arr.size()-1;
	if (type == MAX_HEAP){
		while(current_index > 1 && arr[current_index] > arr[current_index/2]){
			swap(arr[current_index],arr[current_index/2]);
			current_index /=2;
		} 
	}else{
		while(current_index > 1 && arr[current_index] < arr[current_index/2]){
			swap(arr[current_index],arr[current_index/2]);
			current_index /=2;
		} 
	}
}
template <class T>
T Heap<T>::top(){
	return arr[1];
}
template <class T>
T Heap<T>::extract(){
	T result = arr[1];
	arr[1] = arr[arr.size()-1];
	arr.pop_back();
	
	heapify(1,arr.size());
	return result;
}
		
template <class T>
void Heap<T>::heapify(int i,int heapsize){
	int l = i*2;
	int r = i*2+1;
	int v;
	if (type == MAX_HEAP){
		if(l <= heapsize && arr[l] > arr[i]){
			v = l;
		}else v = i;
		if (r <= heapsize && arr[r] > arr[v]){
			v = r;
		}
		if (v != i){
			swap(arr[i],arr[v]);
			heapify(v,heapsize);
		}
	}else{
		if(l <= heapsize && arr[l] < arr[i]){
			v = l;
		}else v = i;
		if (r <= heapsize && arr[r] < arr[v]){
			v = r;
		}
		if (v != i){
			swap(arr[i],arr[v]);
			heapify(v,heapsize);
		}
	}
}
		
template <class T>
void Heap<T>::build_heap(){
	for (int i = arr.size()/2 ; i >= 1;i--){
		heapify(i,arr.size()-1);
	}
}

template <class T>
int Heap<T>::size(){
	return arr.size()-1;
}

template <class T>
void Heap<T>::Sort(){		
	build_heap();
	int heapsize = arr.size()-1;
	for(int i = arr.size()-1 ; i >= 2 ;i-- ){
		swap(arr[1],arr[i]);
		heapsize -= 1;
		heapify(1,heapsize);
	}
}

template <class T>
void Heap<T>::show_list(){
	for(int i = 1 ; i < arr.size();i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
		
template <class T>
void Heap<T>::show_tree(){
	TreeTextHelper::showTree<T>(arr);
	cout << endl;
}

template <class T>
void Heap<T>::sequence_order(){
	for(int i = 1 ; i < arr.size();i++){
		cout << arr[i] << " ";
	}
}
