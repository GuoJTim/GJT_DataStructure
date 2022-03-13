#ifndef TreeTextHelper_H
#define TreeTextHelper_H
#include "../BinaryTree/BinaryTree.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;
class TreeTextHelper{
	public:
		static int calcSpace(int c){
			if(c == 1) return 5;
			else return calcSpace(c-1)*2+3;
		}
		static const int base = 5;
		template<class T>
		static void showTree(std::vector<T> &arr,bool showRoot = false){
			int total_layer = log2(arr.size()-1)+1;
			if(showRoot) {
				int space = calcSpace(total_layer-0-1);
				for(int i = 0 ; i < space ; i++) cout << " ";
				cout << setw(3) << arr[0] << endl;
			}
			for(int index = 1 ; index < arr.size();index++){
				string node = to_string(arr[index]);
				int current_layer;
				current_layer = log2(index);
				int space;
				
				if (log2(index) == ceil(log2(index))){
					if(index != 1)cout << endl;
					space = (total_layer-current_layer == 1) ? 1 : calcSpace(total_layer-current_layer-1);
				}
				else space = calcSpace(total_layer-current_layer);
				for(int i = 0 ; i < space ; i++) cout << " ";
				cout << std::setfill(' ')  << setw(3) << node;
			}
		}
		
		
	
		
		
		template<class T>
		static void showTree(BinaryTree<T> &tree){
			int total_layer = log2(tree.size)+1;
			
			
			queue<TreeNode<T>*> q;
			int index = 1;
			TreeNode<T> *currentNode = tree.root;
			while(index < pow(2,total_layer)){
				int current_layer;
				current_layer = log2(index);
				int space;
				
				if (log2(index) == ceil(log2(index))){
					if(index != 1)cout << endl;
					space = (total_layer-current_layer == 1) ? 1 : calcSpace(total_layer-current_layer-1);
				}
				else space = calcSpace(total_layer-current_layer);
				
				for(int i = 0 ; i < space ; i++) cout << " ";
				if(currentNode != nullptr){
					stringstream ss;
					ss << currentNode->data;
					// idk why setw is not working on overload operator<<
					cout << std::setfill(' ') << setw(3) << ss.str();
					q.push(currentNode->left);
					q.push(currentNode->right);
				}
				else {
					cout << "xxx";
					q.push(nullptr);
					q.push(nullptr);
				}
				currentNode = q.front(); q.pop();
				index++;
			}
		}
		
		
};
#endif
