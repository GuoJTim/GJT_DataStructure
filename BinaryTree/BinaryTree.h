#ifndef BinaryTree_H
#define BinaryTree_H
#include "TreeNode.h"

template <class T>
class BinaryTree{
	public:
		TreeNode<T> *root;
		BinaryTree();
		BinaryTree(const BinaryTree<T>& s);
		void Inorder();
		void Inorder(TreeNode<T> *currentNode);
		void Preorder();
		void Preorder(TreeNode<T> *currentNode);
		void Postorder();
		void Postorder(TreeNode<T> *currentNode);
		void LevelOrder();
		TreeNode<T> *Copy(TreeNode<T> *origNode);
		bool operator==(const BinaryTree &t) const;
		bool Equal(TreeNode<T> *a,TreeNode<T> *b);
		bool isEmpty() const;
};

#include "BinaryTree.cpp"
#endif
