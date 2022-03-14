#include "BinaryTree.h" 
#include "BinarySearchTree.h"
#include <iostream>
#include <ostream>
#include <utility>
using namespace std;
ostream &operator<<(ostream& os,pair<int,int> p){
	os << p.first << "|" << p.second;
	return os;
}

int main(){
	TreeTextHelper::changeElementSize(7);
	
	BinaryTree<int> tree;
	tree.root = new TreeNode<int>(5);
	tree.root->left = new TreeNode<int>(4);
	tree.root->right = new TreeNode<int>(7);
	tree.LevelOrder();
	tree.Inorder();
	
	BinarySearchTree<int> treeS;
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
	fakeDict.root = new TreeNode<string>("xxxxx");
	fakeDict.root->left = new TreeNode<string>("xxxxx");
	fakeDict.root->right = new TreeNode<string>("xxxxx");
	fakeDict.root->right->right = new TreeNode<string>("xxxxx");
	fakeDict.size = 4;
	fakeDict.show_tree();
	
	
	if (dict.Contains(4)){
		cout << *dict.GetValue(4) << endl;
	}
	if (dict.Contains(5)){
		cout << *dict.GetValue(5) << endl;
	}
}
