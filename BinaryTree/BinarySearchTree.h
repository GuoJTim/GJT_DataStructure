#ifndef BinaryTreeSearch_H
#define BinaryTreeSearch_H
#include "BinaryTree.h"
#include <utility> // pair

template <class T>
class BinarySearchTree : public BinaryTree<T>{
	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree<T>& s);
		TreeNode<T>* MINIMUM(TreeNode<T>* node);
		TreeNode<T>* MAXIMUM(TreeNode<T>* node);
		TreeNode<T>* Search(T data);
		TreeNode<T>* Search(TreeNode<T>* node,T data);
		void Successor(TreeNode<T>* node);
		void Predecessor(TreeNode<T>* node);
		void Insert(TreeNode<T>* z);
		void Transplant(TreeNode<T>* u,TreeNode<T>* v);
		void Delete(TreeNode<T>* z);
};


template <class K,class V>
class Dictionary : public BinarySearchTree<std::pair<K,V> >{
	public:
		Dictionary();
		Dictionary(const Dictionary &s);
		bool IsEmpty() const;
		void Insert(const std::pair<K,V>&); //over ride
		void Delete(const K&); //over ride
		pair<K,V>* Get(const K&k);//over ride
		pair<K,V>* Get(TreeNode<std::pair<K,V>>* p,const K &k);//over ride
		TreeNode<pair<K,V>>* Search(K data); // custom search 
		TreeNode<pair<K,V>>* Search(TreeNode<pair<K,V>>* node,K data);
};

#include "BinarySearchTree.cpp"
#endif
