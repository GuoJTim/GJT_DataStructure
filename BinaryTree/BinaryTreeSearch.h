#ifndef BinaryTreeSearch_H
#define BinaryTreeSearch_H
#include "BinaryTree.h"
#include <utility> // pair

template <class T>
class BinaryTreeSearch : public BinaryTree<T>{
	public:
		BinaryTreeSearch();
		BinaryTreeSearch(const BinaryTreeSearch<T>& s);
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
class Dictionary : public BinaryTree<std::pair<K,V> >{
	public:
		Dictionary();
		Dictionary(const Dictionary &s);
		bool IsEmpty() const;
		void Insert(const std::pair<K,V>&);
		void Delete(const K&);
		pair<K,V>* Get(const K&k);
		pair<K,V>* Get(TreeNode<std::pair<K,V>>* p,const K &k);
};

#include "BinaryTreeSearch.cpp"
#endif
