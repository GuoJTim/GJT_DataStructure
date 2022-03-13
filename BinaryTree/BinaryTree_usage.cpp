#include "BinaryTree.h" 
#include "BinaryTreeSearch.h"
#include <iostream>
#include <utility>
using namespace std;


int main(){
	BinaryTree<int> tree;
	tree.root = new TreeNode<int>(5);
	tree.root->left = new TreeNode<int>(4);
	tree.root->right = new TreeNode<int>(7);
	tree.LevelOrder();
	tree.Inorder();
	
	BinaryTreeSearch<int> treeS;
	treeS.Insert(new TreeNode<int>(5));
	treeS.Insert(new TreeNode<int>(4));
	treeS.Insert(new TreeNode<int>(7));
	treeS.LevelOrder();
	treeS.Inorder();
	
	Dictionary<int,int> dict;
	dict.Insert({5,4});
	dict.Insert({7,2});
	pair<int,int> *result = dict.Get(5);
	if (result != nullptr) cout << "find " << result->second << endl;
	pair<int,int> *result2 = dict.Get(6);
	if (result2 != nullptr) cout << "find " << result2->second << endl;
}
