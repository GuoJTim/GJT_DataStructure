#ifndef TreeTextHelper_H
#define TreeTextHelper_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;

template <class T>
class BinaryTree;
template <class T>
class TreeNode;

class TreeTextHelper{
	public:
		static int base;
		static int baseSpace;
		static void changeElementSize(int newSize){
			if (newSize % 2 == 0) {
				cout << "Please make sure the new element size is odd." << endl;
				return;
			}
			base = newSize;
			baseSpace = newSize;
		}
		static int calcSpace(int total_layer,int current_layer){
			int space = (pow(2,(total_layer-current_layer))-1)*(base+1)+1;
			return space;
		}
		
		//static int calcSpace(int c){
		//	if(c == 1) return base;
		//	else return calcSpace(c-1)*2+debug;
		//}
		template<class T>
		static void showTree(std::vector<T> &arr,bool showRoot = false){
			int total_layer = log2(arr.size()-1)+1;
			if(showRoot) {
				int space = calcSpace(total_layer,1);
				for(int i = 0 ; i < space ; i++) cout << " ";
				cout << setw(baseSpace) << arr[0] << endl;
			}
			for(int index = 1 ; index < arr.size();index++){
				string node = to_string(arr[index]);
				int current_layer;
				current_layer = log2(index);
				int space;
				
				if (log2(index) == ceil(log2(index))){
					if(index != 1)cout << endl;
					space = (total_layer-current_layer == 1) ? 1 : calcSpace(total_layer,current_layer+1);
				}
				else space = calcSpace(total_layer,current_layer);
				for(int i = 0 ; i < space ; i++) cout << " ";
				cout << std::setfill(' ')  << setw(baseSpace) << node;
			}
		}
		
		
		template <class T>
		static string getFormat(TreeNode<T> *node){
			stringstream ss;
			ss << node->data;
			return ss.str();
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
					space = (total_layer-current_layer == 1) ? 1 : calcSpace(total_layer,current_layer+1);
				}
				else space = calcSpace(total_layer,current_layer);
				
				for(int i = 0 ; i < space ; i++) cout << " ";
				if(currentNode != nullptr){
					string out = getFormat<T>(currentNode);
					cout << std::setfill(' ') << setw(baseSpace) << out;
					q.push(currentNode->left);
					q.push(currentNode->right);
				}
				else {
					for(int i = 0 ; i < baseSpace;i++) cout << "x";
					q.push(nullptr);
					q.push(nullptr);
				}
				currentNode = q.front(); q.pop();
				index++;
			}
		}
};

int TreeTextHelper::base = 5;
int TreeTextHelper::baseSpace = TreeTextHelper::base;

#endif
