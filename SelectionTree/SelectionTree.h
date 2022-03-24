#ifndef SelectionTree_H
#define SelectionTree_H
#include "../BinaryTree/TreeNode.h"
#include "../Heap/Heap.h"
#include <vector>
#include <functional>


template <class T,class U= std::less<T>>
class WinnerTree{
	private:
		typedef U cmp;
		std::vector<Heap<T,U>> runs;	// split k runs
		std::vector<T> arr;
		std::vector<T> parent;
		int p = 0;						// pointer index
		void init();					//initial the runs
		bool compare(int a,int b);
		
		
	public:
		static int k_run;
		WinnerTree();
		WinnerTree(std::vector<T> &_arr);
		bool isEmpty();
		T extract();
		void show_tree();
		void Insert(T data);
};

template <class T,class U>
int WinnerTree<T,U>::k_run = 4;



template <class T,class U = std::less<T>>
class LoserTree{
	private:
		typedef U cmp;
		std::vector<Heap<T,U>> runs;	// split k runs
		std::vector<T> arr;
		std::vector<T> parent;
		int p = 0;						// pointer index
		void init();					//initial the runs
		bool compare(int a,int b);
		
		
	public:
		static int k_run;
		LoserTree();
		LoserTree(std::vector<T> &_arr);
		bool isEmpty();
		T extract();
		void show_tree();
		void Insert(T data);
};


template <class T,class U>
int LoserTree<T,U>::k_run = 4;
#include "SelectionTree.cpp"
#endif
