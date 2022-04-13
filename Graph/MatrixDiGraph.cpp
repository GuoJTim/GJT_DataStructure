#include "MatrixDiGraph.h"
MatrixDiGraph::MatrixDiGraph(int nodes): MatrixWDiGraph(nodes){
	
}

void MatrixDiGraph::InsertEdge(int u,int v) {
	if (!matrix[u][v]) e++;
	matrix[u][v] = true;
}


MatrixDiGraph::~MatrixDiGraph(){
	
}
