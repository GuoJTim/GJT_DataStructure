#include "LinkedWDiGraph.h"
#include "MatrixWDiGraph.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	LinkedWDiGraph a(10);
	a.InsertEdge(0,5,10);
	a.InsertEdge(0,1,28);
	a.InsertEdge(1,2,16);
	a.InsertEdge(1,6,14);
	a.InsertEdge(2,3,12);
	a.InsertEdge(6,3,18);
	a.InsertEdge(6,4,24);
	a.InsertEdge(3,4,22);
	a.InsertEdge(4,5,25);
	cout << "Test" << endl;
	a.Biconnected();
	a.DFS();
	a.BFS(0);
	
	MatrixWDiGraph b(10);
	b.InsertEdge(0,5,10);
	b.InsertEdge(0,1,28);
	b.InsertEdge(1,2,16);
	b.InsertEdge(1,6,14);
	b.InsertEdge(2,3,12);
	b.InsertEdge(6,3,18);
	b.InsertEdge(6,4,24);
	b.InsertEdge(3,4,22);
	b.InsertEdge(4,5,25);
	cout << "Test" << endl;
	b.Biconnected();
	b.DFS();
	b.BFS(0);
}
