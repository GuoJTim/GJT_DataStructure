#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int nodes): MatrixWGraph(nodes){
	
}
void MatrixGraph::InsertEdge(int u,int v){
	if (!matrix[u][v]) e++;
	if (!matrix[v][u]) e++;
	matrix[u][v] = true;
	matrix[v][u] = true;
}


MatrixGraph::~MatrixGraph(){
	
}
