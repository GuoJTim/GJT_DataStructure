#include "BucketSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include <iostream>
using namespace std;

int part(int v){
	return (v/1) % 10;
}

int main()
{
	vector<float> arr = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	BucketSort<float> bs(arr);
	bs.Sort(arr.size());
	bs.show_list();
	//125,412,394,121,632,694
	vector<int> b = {103,152,311,413,394,121,578,141,632,694,632,694};
	CountingSort<int> cs(b);
	cs.Sort(2);
	std::cout << "test" << std::endl;
	cs.show_list();
	
	vector<int> c = {0,1,2,563,656,445,6,7,8};
	CountingSort<int> cs2;
	cs2.Sort(c,3,5,2);
	for(int i : c) cout << i << " ";
	cout << endl;
	
	vector<int> test = {3,2,1,5,4,3,12,5,2,8,1,6,69,5,11};
	BucketSort<int> bs2(test);
	bs2.Sort(10,&part);
	bs2.show_list();
	
	
	
	vector<int> a = {1943,1542,3111,1125,3412,7334,5127,6575,1612,5081,1101,6432,5594,4314,3161,1456,5123,9453,5127};
	RadixSort<int> rs(a);
	rs.LSD_Sort();
	rs.show_list();
    return 0;
}