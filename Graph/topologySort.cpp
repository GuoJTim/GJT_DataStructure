#include "MatrixDiGraph.h"
#include <iostream>
using namespace std;

int main(){
	MatrixDiGraph topSort(8);
	topSort.InsertEdge(0,1);
	topSort.InsertEdge(0,2);
	topSort.InsertEdge(1,3);
	topSort.InsertEdge(2,3);
	topSort.InsertEdge(3,4);
	topSort.InsertEdge(3,5);
	topSort.InsertEdge(6,7);
	topSort.InsertEdge(2,7);
	for (int i : topSort.topologySort()){
		cout << i << endl;
	}
}
