#include "BinaryTree.h"
#include "../Utils/TreeTextHelper.cpp"
#include <queue>
#include <iostream>
using namespace std;
template <class T>
BinaryTree<T>::BinaryTree(){
	root = nullptr;
}


template <class T>
void BinaryTree<T>::Inorder(){
	Inorder(root);
	cout << endl;
}

template <class T>
void BinaryTree<T>::Inorder(TreeNode<T> *currentNode){
	if(currentNode != nullptr){
		Inorder(currentNode->left);
		cout << currentNode->data << " ";
		Inorder(currentNode->right);
	}
}

template <class T>
void BinaryTree<T>::Preorder(){
	Preorder(root);
	cout << endl;
}

template <class T>
void BinaryTree<T>::Preorder(TreeNode<T> *currentNode){
	if(currentNode != nullptr){
		cout << currentNode->data << " ";
		Preorder(currentNode->left);
		Preorder(currentNode->right);
	}
}

template <class T>
void BinaryTree<T>::Postorder(){
	Postorder(root);
	cout << endl;
}

template <class T>
void BinaryTree<T>::Postorder(TreeNode<T> *currentNode){
	if(currentNode != nullptr){
		Postorder(currentNode->left);
		Postorder(currentNode->right);
		cout << currentNode->data << " ";
	}
}

template <class T>
void BinaryTree<T>::LevelOrder(){
	queue<TreeNode<T>*> q;
	TreeNode<T> *currentNode = root;
	while(currentNode != nullptr){
		cout << currentNode->data << " ";
		if (currentNode->left != nullptr) q.push(currentNode->left);
		if (currentNode->right != nullptr) q.push(currentNode->right);
		if (q.empty()) {
			
			cout << endl;	
			return;
		}
		currentNode = q.front(); q.pop();
	}
}

template <class T>
void BinaryTree<T>::show_tree(){
	TreeTextHelper::showTree<T>(*this);
	cout << endl;
}



template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& s){
	root = Copy(s.root);
}

template <class T>
TreeNode<T>* BinaryTree<T>::Copy(TreeNode<T> *origNode){
	if(origNode == nullptr) return nullptr;
	return new TreeNode<T>(origNode->data,Copy(origNode->left),Copy(origNode->right));
}


template <class T>
bool BinaryTree<T>::operator==(const BinaryTree &t) const{
	return Equal(root,t.root);
}

template <class T>
bool BinaryTree<T>::Equal(TreeNode<T> *a,TreeNode<T> *b){
	if ((a == nullptr) && (b == nullptr)) return true;
	return ( a != nullptr && b != nullptr 
			&& (a->data == b->data)
			&& Equal(a->left,b->left)
			&& Equal(a->right,b->right));
}

template <class T>
bool BinaryTree<T>::isEmpty() const{
	return root == nullptr;
}


