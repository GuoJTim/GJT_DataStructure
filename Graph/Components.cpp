#include "LinkedGraph.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	LinkedGraph test(12);
	test.InsertEdge(1,4);
	test.InsertEdge(1,2);
	test.InsertEdge(2,5);
	test.InsertEdge(2,3);
	test.InsertEdge(3,5);
	
	test.InsertEdge(6,9);
	test.InsertEdge(8,9);
	
	test.InsertEdge(11,10);
	
	test.Components();
}
