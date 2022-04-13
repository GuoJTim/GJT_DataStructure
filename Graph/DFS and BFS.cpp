#include "LinkedGraph.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	LinkedGraph test(8);
	test.InsertEdge(0,1);
	test.InsertEdge(0,2);
	
	test.InsertEdge(1,0);
	test.InsertEdge(1,3);
	test.InsertEdge(1,4);
	
	test.InsertEdge(2,0);
	test.InsertEdge(2,5);
	test.InsertEdge(2,6);
	
	test.InsertEdge(3,1);
	test.InsertEdge(3,7);
	
	test.InsertEdge(4,1);
	test.InsertEdge(4,7);
	
	test.InsertEdge(5,2);
	test.InsertEdge(5,7);
	
	test.InsertEdge(6,2);
	test.InsertEdge(6,7);
	
	test.InsertEdge(7,3);
	test.InsertEdge(7,4);
	test.InsertEdge(7,5);
	test.InsertEdge(7,6);
	
	test.DFS();
	cout << endl;
	test.BFS(1);
	
}
