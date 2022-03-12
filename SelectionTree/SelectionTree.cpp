#include "SelectionTree.h"
#include "../Utils/TreeTextHelper.cpp"
		
template <class T>
void WinnerTree<T>::init(){
	for(int i = 0 ; i < k_run;i++){
		if(type == MAX) runs[i] = Heap<T>(MAX_HEAP); // max heap
		else runs[i] = Heap<T>(MIN_HEAP); // min heap
		runs[i].Insert(type == MIN? INT_MAX:INT_MIN);
	}
}
template <class T>
WinnerTree<T>::WinnerTree(SelectionType type){
	runs.resize(k_run);
	this->type = type;
	init();
}
template <class T>
WinnerTree<T>::WinnerTree(SelectionType type,vector<T> _arr){
	runs.resize(k_run);
	this->type = type;
	init();
	for(int i = 0 ; i < _arr.size();i++){
		runs[p++%k_run].Insert(_arr[i]);
	}
}

template <class T>
void WinnerTree<T>::buildTree(){
	arr.resize(k_run*2,0);
	for(int i = 0 ; i < k_run;i++){
		arr[k_run+i] = runs[i].extract();//top
	}
	for(int i = k_run-1 ; i >= 1 ; i--){
		arr[i] = compare(i);
	}
}
		
template <class T>
T WinnerTree<T>::compare(int index){
	if (type == MAX){
		return arr[index*2] >= arr[index*2+1] ? arr[index*2] : arr[index*2+1];
	}else{
		return arr[index*2] <= arr[index*2+1] ? arr[index*2] : arr[index*2+1];
	}
}

template <class T>
bool WinnerTree<T>::isEmpty(){
	return (arr[1] == INT_MAX && type == MIN)||
			(arr[1] == INT_MIN && type == MAX);
}

template <class T>
T WinnerTree<T>::extract(){
	T root = arr[1];
	extract(1,1);
	return root;
}

template <class T>
void WinnerTree<T>::extract(int index,int prev_index){
	if (index >= k_run) {
		arr[index] = runs[index-k_run].extract();
		
	}
	else if (type == MAX){
		if (arr[index*2] >= arr[index*2+1]){
			extract(index*2,index);
		}else extract(index*2+1,index);
	}else{
		if (arr[index*2] <= arr[index*2+1]){
			extract(index*2,index);
		}else extract(index*2+1,index);
	}
	if (type == MAX){
		if (arr[prev_index*2] >= arr[prev_index*2+1]) arr[prev_index] = arr[prev_index*2];
		else arr[prev_index] = arr[prev_index*2+1];
	}else{
		if (arr[prev_index*2] <= arr[prev_index*2+1]) arr[prev_index] = arr[prev_index*2];
		else arr[prev_index] = arr[prev_index*2+1];
	}
}
	
template <class T>	
void WinnerTree<T>::show_tree(){
	TreeTextHelper::showTree<T>(arr);
	cout << endl;
	cout << endl;
}




template <class T>
void LoserTree<T>::init(){
	for(int i = 0 ; i < k_run;i++){
		if(type == MAX) runs[i] = Heap<T>(MAX_HEAP); // max heap
		else runs[i] = Heap<T>(MIN_HEAP); // min heap
		runs[i].Insert(type == MIN? INT_MAX:INT_MIN);
	}
}

template <class T>
LoserTree<T>::LoserTree(SelectionType type){
	runs.resize(k_run);
	this->type = type;
	init();
}

template <class T>
LoserTree<T>::LoserTree(SelectionType type,vector<T> _arr){
	runs.resize(k_run);
	this->type = type;
	init();
	for(int i = 0 ; i < _arr.size();i++){
		runs[p++%k_run].Insert(_arr[i]);
	}
}
	
template <class T>	
void LoserTree<T>::heapify(int i){
	pair<T,T> p = compare(i);
	arr[i] = p.second;
	T ret = p.first;
	int ret_pos;
	if (p.first == arr[i*2]){
		parent[i] = i*2+1;
		ret_pos = i*2;
	}else{
		parent[i] = i*2;
		ret_pos = i*2+1;
	}
	int current_i = i/2;
			
	int current = i/2;
	// && 
	//	((arr[current] != INT_MIN && type == MAX)||
	//	(arr[current]  != INT_MAX && type == MIN))
	//
	while(current >= 1 && parent[current] != -1){
		//ret 為目前 獲勝者 arr[current] 為原本的 獲勝者 
		pair<T,T> cp = compare(ret,arr[current]);//check the winner and loser
		
		if(ret == cp.first){ // still the winner 還是獲勝者 則 原本保留 
			
		}else { // 不適獲勝者了 原本的 贏了 原本上升 
			swap(ret_pos,parent[current]);
		} 
		arr[current] = cp.second;
		ret = cp.first;
		current /= 2;
		current_i /= 2;
	}
	arr[current] = ret;
	parent[current_i] = ret_pos;
}
		

template <class T>		
void LoserTree<T>::buildTree(){
	parent.resize(k_run,-1);
	if( type == MIN) arr.resize(k_run*2,INT_MAX);
	if( type == MAX) arr.resize(k_run*2,INT_MIN);
	for(int i = 0 ; i < k_run;i++){
		arr[k_run+i] =runs[i].extract();//top
	}
	for(int i = k_run/2 ; i < k_run ; i++){
		heapify(i);
	}
}
		
// <win,lose>
template <class T>
pair<T,T> LoserTree<T>::compare(int index){
	return compare(arr[index*2],arr[index*2+1]);
}
		
template <class T>
pair<T,T> LoserTree<T>::compare(T &a,T &b){
	if (type == MAX){
		return a >= b ? make_pair(a,b) : make_pair(b,a);
	}else{
		return a <= b ? make_pair(a,b) : make_pair(b,a);
	}
}

template <class T>
bool LoserTree<T>::isEmpty(){
	return (arr[0] == INT_MAX && type == MIN)||
			(arr[0] == INT_MIN && type == MAX);
}

template <class T>
T LoserTree<T>::extract(){
	T root = arr[0]; // extract 0
	int index = parent[0];// find the arr
	arr[index] = runs[index-k_run].extract(); //extract the runs
	//then do again
	heapify(index/2);
	return root;
}

template <class T>
int LoserTree<T>::find_index(int index){
	if (index >= k_run) {
		arr[index] = runs[index-k_run].extract();
		return index;
	}
	else if (type == MAX){
		if (arr[index*2] >= arr[index*2+1]){
			return find_index(index*2);
		}else return find_index(index*2+1);
	}else{
		if (arr[index*2] <= arr[index*2+1]){
			return find_index(index*2);
		}else return find_index(index*2+1);
	}
}
	
template <class T>	
void LoserTree<T>::show_tree(){
	TreeTextHelper::showTree<T>(arr,true);
	cout << endl;
}
