#include "MatrixWDiGraph.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	MatrixWDiGraph g(5);
	g.InsertEdge(0,1,3);
	g.InsertEdge(1,3,1);
	g.InsertEdge(1,4,7);
	g.InsertEdge(2,1,4);
	g.InsertEdge(3,2,-5);
	g.InsertEdge(4,3,6);
	g.InsertEdge(0,4,-4);
	g.InsertEdge(0,2,8);
	g.InsertEdge(3,0,2);
	cout << "test" << endl;
	g.floyd_warshall();
	cout << "test" << endl;
	g.bellman_ford(0);
	g.bellman_ford(1);
	g.bellman_ford(2);
	g.bellman_ford(3);
	g.bellman_ford(4);
	
}
