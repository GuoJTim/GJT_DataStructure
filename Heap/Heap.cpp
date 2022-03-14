#include "Heap.h"
#include "../Utils/TreeTextHelper.cpp"


#include <iostream>
template <class T>
Heap<T>::Heap(){
	this->type = MAX_HEAP;
	
	arr.push_back(0);
}

template <class T>
Heap<T>::Heap(HeapType type){
	this->type = type;
	
	arr.push_back(0);
}
template <class T>
Heap<T>::Heap(HeapType type,vector<T> _arr){
	this->type = type;
	
	arr.push_back(0);
	
	for(T data: _arr) Insert(data);
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
		swap(arr[1],arr[i]); //把最大的往後放 
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


//back track algorithm
template <class T>
int Heap<T>::find_target(T &data,int current){
	if (current >= arr.size()) return -1;
	if (arr[current] == data) return current;
	int left = -1,right = -1;
	if ((arr[current*2] >= data && type == MAX_HEAP)|| arr[current*2] <= data && type == MIN_HEAP ) left = find_target(data,current*2);
	if ((arr[current*2+1] >= data && type == MAX_HEAP)|| arr[current*2+1] <= data && type == MIN_HEAP ) right = find_target(data,current*2+1);
	return max(left,right); // return the max for less heapify operation
}

template <class T>
void Heap<T>::Delete(T data){
	//delete a data
	int current = 1;//root
	int index = find_target(data,current);
	if (index == -1) {
		return; //not found
	}else{// do heapify
		current = index;
		while(current <= arr.size()/2 ){
			if (current*2+1 >= arr.size()){
				//right child with no data
				arr[current] = arr[current*2];
				current*=2;
			}
			else if ( (arr[current*2] >= arr[current*2+1] && type == MAX_HEAP) ||
						(arr[current*2] <= arr[current*2+1] && type == MIN_HEAP) ){
				//left is bigger than right (max
				arr[current] = arr[current*2];
				current = current*2;
			}else{
				arr[current] = arr[current*2+1];
				current = current*2+1;
			}
		}
		current /= 2;
		arr[current] = arr.back();// can use the last element to swap
		// then do the (bottom up)heapfiy here again and delete the last element in the array
		
		//cout << "last pop index is :" << current << endl; 
		//cout << "data:" << arr[current] << endl;
		arr.pop_back();// remove back
		
		current /= 2;
		//show first
		
		if (type == MAX_HEAP){
			while(current > 1 && arr[current] > arr[current/2]){
				swap(arr[current],arr[current/2]);
				current /=2;
			} 
		}else{
			while(current > 1 && arr[current] < arr[current/2]){
				swap(arr[current],arr[current/2]);
				current /=2;
			} 
		}
		cout << current << endl;
	}
}
