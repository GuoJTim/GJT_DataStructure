#include "IntroSort.h"
#include "../Utils/CTimer.cpp"
#include <iostream>

template <typename T>
bool checkSorted(vector<T>& data) {
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i - 1] < data[i]) {
            return false;
        }
    }
    return true;
}

using namespace std;
int main(){
	vector<int> arr({
		4,50,34,40,22,54,94,3,94,38,8,95,0,36,54,54,81,30,24,98,12,25,43,0,52,52,88,22,83,70,96,57,89,53,13,64,74,18,37,86,73,76,15,1,93,69,77,81,29,78,14,45,67,1,0,41,60,63,74,16,75,75,36,49,68,5,67,29,15,84,47,77,40,80,24,61,25,7,85,83,81,47,10,39,22,72,87,64,92,27,50,69,12,54,23,85,38,75,73,94
	});
	
	IntroSort<int,greater<int>> test(arr);
	CTimer::calc([&](){
		test.Sort();
	});
	cout << checkSorted(test.arr) << endl;
	test.show_list();
}