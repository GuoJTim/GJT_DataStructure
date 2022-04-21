#include "LinkedGraph.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	LinkedGraph test(10);
	test.InsertEdge(0,1);
	test.InsertEdge(4,3);
	test.InsertEdge(1,2);
	test.InsertEdge(1,3);
	test.InsertEdge(2,4);
	
	test.InsertEdge(5,3);
	test.InsertEdge(5,6);
	test.InsertEdge(5,7);
	
	test.InsertEdge(6,7);
	test.InsertEdge(7,9);
	test.InsertEdge(7,8);
	
	test.Biconnected();

}
