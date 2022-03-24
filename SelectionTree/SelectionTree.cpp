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
	parent.resize(k_run,-1);
	arr.resize(k_run*2,LIMIT_VALUE);
	for(int i = 0 ; i < k_run;i++){
		runs[i] = Heap<T,U>();
		runs[i].Insert(LIMIT_VALUE);
	}
}

template <class T,class U>
LoserTree<T,U>::LoserTree(T LIMIT_VALUE){
	this->LIMIT_VALUE = LIMIT_VALUE;
	init();
}

template <class T,class U>
LoserTree<T,U>::LoserTree(vector<T> &_arr,T LIMIT_VALUE){
	this->LIMIT_VALUE = LIMIT_VALUE;
	init();
	for(T &obj:_arr){
		Insert(obj);
	}
}
		
// <win,lose>
template <class T,class U>
pair<T,T> LoserTree<T,U>::compare(int index){
	return compare(arr[index*2],arr[index*2+1]);
}
		
template <class T,class U>
pair<T,T> LoserTree<T,U>::compare(T &a,T &b){
	if (b == LIMIT_VALUE) return make_pair(a,b);
	if (a == LIMIT_VALUE) return make_pair(b,a);
	if(cmp()(a,b)) return make_pair(a,b);
	else make_pair(b,a); 
	
}

template <class T,class U>
bool LoserTree<T,U>::isEmpty(){
	return arr[0] == LIMIT_VALUE;
}

template <class T,class U>
T LoserTree<T,U>::extract(){
	T root = arr[0]; // extract 0
	int index = parent[0];// find the arr
	runs[index-k_run].extract();
	arr[index] = runs[index-k_run].top(); //extract the runs
	//then do again
	
	update(index/2);
	return root;
}

template <class T,class U>
void LoserTree<T,U>::update(int i){
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
		
		if(ret == cp.first){ // still the winner 還是獲勝者 則原本保留 
			
		}else { // 不是獲勝者了 原本贏了 原本上升 
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
	int current = run_index + k_run;
	arr[current] = runs[run_index].top();	
}

template <class T,class U>
void LoserTree<T,U>::build_tree(){
	for(int i = k_run/2 ; i < k_run ; i++){
		update(i);
	}	
}

	
template <class T,class U>	
void LoserTree<T,U>::show_tree(){
	TreeTextHelper::showTree<T>(arr,true,parent);
	cout << endl;
}
