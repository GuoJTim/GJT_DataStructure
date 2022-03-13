#include "BinaryTree.h" 
#include "BinaryTreeSearch.h"
#include <iostream>
#include <ostream>
#include <utility>
using namespace std;


ostream &operator<<(ostream& os,pair<int,int> p){
	os << p.first << "|" << p.second;
	return os;
}

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
	
	TreeNode<int> *node = new TreeNode<int>(1);
	treeS.Insert(new TreeNode<int>(8));
	
	treeS.Insert(node);
	treeS.Delete(node);
	
	
	Dictionary<int,int> dict;
	dict.Insert({5,4});
	dict.Insert({7,2});
	dict.Insert({3,1});
	dict.Insert({9,7});
	dict.show_tree();
	
	BinaryTree<string> fakeDict; // just show the display function (show_tree)
	fakeDict.root = new TreeNode<string>("5|4");
	fakeDict.root->left = new TreeNode<string>("3|1");
	fakeDict.root->right = new TreeNode<string>("7|2");
	fakeDict.root->right->right = new TreeNode<string>("9|7");
	fakeDict.size = 4;
	fakeDict.show_tree();
	
	
	
	pair<int,int> *result = dict.Get(5);
	if (result != nullptr) cout << "find " << result->second << endl;
	pair<int,int> *result2 = dict.Get(6);
	if (result2 != nullptr) cout << "find " << result2->second << endl;
}
