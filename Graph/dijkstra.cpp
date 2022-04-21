#include "MatrixWDiGraph.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	MatrixWDiGraph g(5);
	g.InsertEdge(0,1,10);
	g.InsertEdge(0,2,5);
	g.InsertEdge(1,3,1);
	g.InsertEdge(1,2,2);
	g.InsertEdge(2,1,3);
	g.InsertEdge(2,4,2);
	g.InsertEdge(2,3,9);
	g.InsertEdge(4,0,7);
	g.InsertEdge(4,3,6);
	g.InsertEdge(3,4,4);
	cout << "test" << endl;
	g.dijkstra(0);
	cout << "test" << endl;
	
}
