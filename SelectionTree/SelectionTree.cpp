#include "SelectionTree.h"
#include "../Utils/TreeTextHelper.cpp"

template <class T,class U>
void WinnerTree<T,U>::init(){
	runs.resize(k_run);
	parent.resize(k_run*2,-1);
	arr.resize(k_run*2);
	for(int i = 0 ; i < k_run;i++){
		runs[i] = Heap<T,U>();
	}
	for(int i = k_run; i < k_run*2;i++){
		parent[i] = i; // get current parent for rapidly changes
	}
}
template <class T,class U>
WinnerTree<T,U>::WinnerTree(){
	init();
}
template <class T,class U>
WinnerTree<T,U>::WinnerTree(vector<T> &_arr){
	init();
	for(T &obj:_arr){
		Insert(obj);
	}
}

template <class T,class U>
bool WinnerTree<T,U>::compare(int a,int b){
	return cmp()(arr[a],arr[b]);
}
			

template <class T,class U>
bool WinnerTree<T,U>::isEmpty(){
	return parent[1] == -1;
}

template <class T,class U>
T WinnerTree<T,U>::extract(){
	int run_index = parent[1]-k_run;
	T root = runs[run_index].extract();
	int current = run_index + k_run;
	if (!runs[run_index].size()) {
		// is empty
		parent[current] = -1;
	}else {
		arr[current] = runs[run_index].top();
		parent[current] = current;
	}
	
	current /= 2;
	while(current >= 1){
		if (parent[current*2] == -1){
			//left tree
			parent[current] = parent[current*2+1];
			arr[current] = arr[current*2+1];
			current /= 2;
		}
		else if (parent[current*2+1] == -1){
			//right tree
			parent[current] = parent[current*2];
			arr[current] = arr[current*2];
			current /= 2;
		}else {
			if(compare(current*2,current*2+1)){
				parent[current] = parent[current*2];
				arr[current] = arr[current*2];
			}else{
				parent[current] = parent[current*2+1];
				arr[current] = arr[current*2+1];
			}
			current /= 2;
		}
		
	}
	
	
	return root;
}

template <class T,class U>	
void WinnerTree<T,U>::show_tree(){
	TreeTextHelper::showTree<T>(arr,false,parent);
	cout << endl;
	cout << endl;
}

template <class T,class U>
void WinnerTree<T,U>::Insert(T data){
	int run_index = p%k_run;	
	p++;
	if(!runs[run_index].size()){
		//is empty
		runs[run_index].Insert(data); 
	}else{
		T orig = runs[run_index].top();
		runs[run_index].Insert(data); 
		if (orig == runs[run_index].top()){
			// no need change
			return;
		}
	}
	int current = run_index + k_run;
	arr[current] = runs[run_index].top();
	while(current > 1 && (parent[current/2] == -1 || compare(current,current/2))){
		parent[current/2] = parent[current];
		arr[current/2] = arr[current];
		current /= 2;
	}
}

//-----------------------------------------------------------------------

template <class T,class U>
void LoserTree<T,U>::init(){
	runs.resize(k_run);
	parent.resize(k_run*2,-1);
	arr.resize(k_run*2);
	for(int i = 0 ; i < k_run;i++){
		runs[i] = Heap<T,U>();
	}
	for(int i = k_run; i < k_run*2;i++){
		parent[i] = i; // get current parent for rapidly changes
	}
}

template <class T,class U>
LoserTree<T,U>::LoserTree(){
	init();
}

template <class T,class U>
LoserTree<T,U>::LoserTree(vector<T> &_arr){
	init();
	for(T &obj:_arr){
		Insert(obj);
	}
}
		
template <class T,class U>
bool LoserTree<T,U>::compare(int a,int b){
	return cmp()(arr[a],arr[b]);
}

template <class T,class U>
bool LoserTree<T,U>::isEmpty(){
	return parent[1] == -1;
}

template <class T,class U>
T LoserTree<T,U>::extract(){
	
}


template <class T,class U>
void LoserTree<T,U>::Insert(T data){
	int run_index = p%k_run;	
	p++;
	if(!runs[run_index].size()){
		//is empty
		runs[run_index].Insert(data); 
	}else{
		T orig = runs[run_index].top();
		runs[run_index].Insert(data); 
		if (orig == runs[run_index].top()){
			// no need change
			return;
		}
	}
	
	//  x
	// 4 5
	//
	// if is empty just push
	// 
	//
	
	int current = run_index + k_run;
	arr[current] = runs[run_index].top();
	int cmp_index = current;
	
	//&& (parent[current/2] == -1 || compare(current,current/2))
	while(current > 0 && (parent[current/2] == -1 || compare(cmp_index,current/2))){
		if (parent[current/2] == -1){
			parent[current/2] = parent[cmp_index];
			arr[current/2] = arr[cmp_index];	
		}
		else if (compare(cmp_index,current/2)){
			//this is the winner
			int temp_cur = current/2;
			while(temp_cur > 0 && parent[current/2] == parent[temp_cur/2]){
				parent[temp_cur/2] = cmp_index;
				arr[temp_cur/2] = arr[cmp_index];
				temp_cur /= 2;
			}
		}else{
			//lose
			arr[current/2] = arr[cmp_index];
			swap(cmp_index,parent[current/2]);
			
			
		}
		current /= 2;
	}
}

	
template <class T,class U>	
void LoserTree<T,U>::show_tree(){
	TreeTextHelper::showTree<T>(arr,true,parent);
	cout << endl;
}
