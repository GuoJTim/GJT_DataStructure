#ifndef TreeNode_H
#define TreeNode_H

template <class T>
class TreeNode{
	public:
		TreeNode *left;
		TreeNode *right;
		TreeNode *parent;// used for binary tree search
		T data;
		TreeNode(T data,TreeNode *left,TreeNode *right):data(data),left(left),right(right),parent(nullptr){}
		TreeNode(T data):data(data),left(nullptr),right(nullptr),parent(nullptr){}
};

#endif
