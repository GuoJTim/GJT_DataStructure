#include "SelectionTree.h" 
#include <iostream>
#include <limits.h>
using namespace std;


int main(){
	TreeTextHelper::changeElementSize(3);
	WinnerTree<int>::k_run = 4;
	vector<int> v = {10,9,20,6,8,9,90,17};
	WinnerTree<int> winnerTree(v);
	winnerTree.show_tree();
	
	cout << winnerTree.extract() << endl;
	winnerTree.show_trede();
	winnerTree.Insert(5);
	winnerTree.show_tree();
	
	
	while(!winnerTree.isEmpty()){
		cout << winnerTree.extract() << endl;
	}
	//winner tree with min 
	
	// initial k_run is 4
	LoserTree<int>::k_run = 4;
	vector<int> v2 = {10,9,20,6,8,9,90,17};
	LoserTree<int> loserTree(v2,INT_MAX);
	loserTree.build_tree(); // wtf i dont want this 
	loserTree.show_tree();
	
	
	while(!loserTree.isEmpty()){
		cout << loserTree.extract() << endl;
		//loserTree.show_tree();
	}
	
}
