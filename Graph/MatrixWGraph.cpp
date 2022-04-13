#include "MatrixWGraph.h"
MatrixWGraph::MatrixWGraph(int nodes): MatrixWDiGraph(nodes){
	
}
void MatrixWGraph::InsertEdge(int u,int v){
	InsertEdge(u,v,0);//this may cause error
}

void MatrixWGraph::InsertEdge(int u,int v,double w) {
	if (!matrix[u][v]) e++;
	if (!matrix[v][u]) e++;
	matrix[u][v] = true;
	matrix[v][u] = true;
	weight[u][v] = w;
	weight[v][u] = w;
}


MatrixWGraph::~MatrixWGraph(){
	
}
