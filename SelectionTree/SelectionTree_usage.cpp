#include "SelectionTree.h" 
#include <iostream>
using namespace std;


int main(){
	TreeTextHelper::changeElementSize(11);
	WinnerTree<int>::k_run = 16;
	WinnerTree<int> winnerTree(MIN,{6,5,4,5,6});
	winnerTree.buildTree();
	winnerTree.show_tree();
	
	
	while(!winnerTree.isEmpty()){
		cout << winnerTree.extract() << endl;
	}
	//winner tree with min 
	
	// initial k_run is 4
	LoserTree<int> loserTree(MAX,{6,5,4,5,6});
	loserTree.buildTree();
	loserTree.show_tree();
	
	
	while(!loserTree.isEmpty()){
		cout << loserTree.extract() << endl;
	}
	
}
