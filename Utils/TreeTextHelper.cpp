#ifndef TreeTextHelper_H
#define TreeTextHelper_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
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
				cout << setw(3) << node;
			}
		}
};
#endif
