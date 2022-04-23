#include "LinkedWDiGraph.h"
#include "MatrixWDiGraph.h"
#include <bits/stdc++.h>
using namespace std;

void func(int ff,LinkedWDiGraph &g,MatrixWDiGraph &g2){
	
	g.bellman_ford(ff);
	g.dijkstra(ff);
	
	
	
	g2.bellman_ford(ff);
	g2.dijkstra(ff);
}


int main(){
	LinkedWDiGraph g(5);
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
	MatrixWDiGraph g2(5);
	g2.InsertEdge(0,1,10);
	g2.InsertEdge(0,2,5);
	g2.InsertEdge(1,3,1);
	g2.InsertEdge(1,2,2);
	g2.InsertEdge(2,1,3);
	g2.InsertEdge(2,4,2);
	g2.InsertEdge(2,3,9);
	g2.InsertEdge(4,0,7);
	g2.InsertEdge(4,3,6);
	g2.InsertEdge(3,4,4);
	int n;
	g.floyd_warshall();
	g2.floyd_warshall();
	while(cin >> n) func(n,g,g2);
	
	
}
