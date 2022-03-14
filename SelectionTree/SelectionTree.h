#ifndef SelectionTree_H
#define SelectionTree_H
#include "../Heap/Heap.h"
#include <vector>

typedef enum SelectionType{
	MAX,
	MIN
}SelectionType;

template <class T>
class WinnerTree{
	public:
		static int k_run;
		int c = 0;
		std::vector<Heap<T>> runs; // split k runs
		std::vector<T> arr;
		SelectionType type;
		int p = 0; // pointer index
		
		//initial the runs
		void init();
		WinnerTree(SelectionType type);
		WinnerTree(SelectionType type,std::vector<T> _arr);
		void buildTree();
		T compare(int index);
		bool isEmpty();
		T extract();
		void extract(int index,int prev_index);
		void show_tree();
};

template <class T>
int WinnerTree<T>::k_run = 4;


template <class T>
class LoserTree{
	public:
		static int k_run;
		int c = 0;
		std::vector<Heap<T>> runs; // split k runs
		std::vector<T> parent; // mem the prev pos
		std::vector<T> arr;
		SelectionType type;
		int p = 0; // pointer index
		
		//initial the runs
		void init();
		LoserTree(SelectionType type);
		LoserTree(SelectionType type,std::vector<T> _arr);
		void heapify(int i);
		void buildTree();
		std::pair<T,T> compare(int index);
		std::pair<T,T> compare(T &a,T &b);
		bool isEmpty();
		T extract();
		int find_index(int index);
		void show_tree();
};


template <class T>
int LoserTree<T>::k_run = 4;
#include "SelectionTree.cpp"
#endif
