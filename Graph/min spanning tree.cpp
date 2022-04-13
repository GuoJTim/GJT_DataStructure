#include "MatrixWGraph.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	MatrixWGraph test(7);
	test.InsertEdge(0,5,10);
    test.InsertEdge(0,1,28);
    test.InsertEdge(1,6,14);
    test.InsertEdge(1,2,16);
    test.InsertEdge(2,3,12);
    test.InsertEdge(3,6,18);
    test.InsertEdge(3,4,22);
    test.InsertEdge(4,6,24);
    test.InsertEdge(4,5,25);
	cout << test.Sollin();

}
