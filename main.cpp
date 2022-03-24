#include "BinaryTree/BinarySearchTree.h"
#include "SelectionTree/SelectionTree.h"
#include "Heap/Heap.h"
#include <iostream>
using namespace std;

/* overload operator << for dictionary show_tree function */
ostream &operator<<(ostream& os,pair<int,char> p){
	os << p.first << "|" << p.second;
	return os;
}



int main(){
	/* --Binary Search Tree-- */
	cout << endl << endl << setw(5) << "Binary Search Tree" << endl;
	vector<int> sequence = {10,6,8,7,15,3,9,13,12,5,14,16};
	vector<TreeNode<int>*> seq_node; //used for remove a node
	BinarySearchTree<int> BST;
	for (int i : sequence) {
		TreeNode<int> *newNode = new TreeNode<int>(i);
		seq_node.push_back(newNode);
		BST.Insert(newNode);	
	}
	BST.show_tree();
	cout << endl;
	cout << "Inorder:" << endl;
	BST.Inorder();
	cout << "Preorder:" << endl;
	BST.Preorder();
	cout << "Postorder:" << endl;
	BST.Postorder();
	cout << "Levelorder:" << endl;
	BST.LevelOrder();
	cout << endl;
	BST.Delete(seq_node[4]); //remove 15
	cout << "Delete 15:" << endl;
	BST.show_tree();
	cout << endl;
	BST.Insert(new TreeNode<int>(0)); // add 0
	cout << "Add 0:" << endl;
	BST.show_tree();
	
	
	/* --Dictionary-- */
	cout << endl << endl << setw(30) << "Dictionary" << endl;
	Dictionary<int,char> dict; // included in BinarySearchTree.h
	dict.Insert({6,'w'});
	dict.Insert({7,'x'});
	dict.Insert({1,'z'});
	cout << "dictionary Tree:" << endl;
	dict.show_tree();//need overload operator
	pair<int,char> *entry = dict.Get(7);
	if (entry != nullptr) cout << entry->second << endl;
	else cout << "not found" << endl;
	entry = dict.Get(1);
	if (entry != nullptr) cout << entry->second << endl;
	else cout << "not found" << endl;
	entry = dict.Get(2);
	if (entry != nullptr) cout << entry->second << endl;
	else cout << "not found" << endl;
	
	/* --Selection Tree-- */
	cout << endl << endl << setw(30) << "Selection Tree" << endl;
	WinnerTree<int> winnerTree(MAX,sequence); //max winner tree
	winnerTree.buildTree();// require buildTree first
	cout << "max winner tree ("<< WinnerTree<int>::k_run <<"runs) :" << endl;
	winnerTree.show_tree();
	
	cout << "ordered list:";
	while(!winnerTree.isEmpty()){
		cout << winnerTree.extract() << " ";
	}cout << endl;
	
	LoserTree<int> loserTree(MAX,sequence); //max loser tree
	loserTree.buildTree();// require buildTree first
	cout << "max loser tree ("<< LoserTree<int>::k_run <<"runs) :" << endl;
	loserTree.show_tree();
	
	cout << "ordered list:";
	while(!loserTree.isEmpty()){
		cout << loserTree.extract() << " ";
	}cout << endl;
	
	WinnerTree<int> winnerTree2(MIN,sequence); //min winner tree
	winnerTree2.buildTree();// require buildTree first
	cout << "min winner tree ("<< WinnerTree<int>::k_run <<"runs) :" << endl;
	winnerTree2.show_tree();
	
	cout << "ordered list:";
	while(!winnerTree2.isEmpty()){
		cout << winnerTree2.extract() << " ";
	}cout << endl;
	
	LoserTree<int>::k_run = 8;// change the k_runs from 4 to 8 ( 4 is init
	LoserTree<int> loserTree2(MIN,sequence); //min loser tree
	loserTree2.buildTree();// require buildTree first
	cout << "min loser tree ("<< LoserTree<int>::k_run <<"runs) :" << endl;
	loserTree2.show_tree();
	
	cout << "ordered list:";
	while(!loserTree2.isEmpty()){
		cout << loserTree2.extract() << " ";
	}cout << endl;
	
	/* --Heap-- */
	cout << endl << endl << setw(30) << "Heap" << endl;
	Heap<int> max_heap(MAX_HEAP); // max heap
	for(int i:sequence) max_heap.Insert(i);
	cout << "max heap tree:" << endl;
	max_heap.show_tree();//show tree
	cout << "Delete 15";
	max_heap.Delete(15);
	max_heap.show_tree();//show tree
	cout << "Insert 10";
	max_heap.Insert(10);
	max_heap.show_tree();//show tree
	
	
	Heap<int> min_heap(MIN_HEAP); // min heap
	for(int i:sequence) min_heap.Insert(i);
	cout << "min heap tree:" << endl;
	min_heap.show_tree();//show tree
	cout << "Delete 15";
	min_heap.Delete(15);
	min_heap.show_tree();//show tree
	cout << "Insert 10";
	min_heap.Insert(10);
	min_heap.show_tree();//show tree
	
}
