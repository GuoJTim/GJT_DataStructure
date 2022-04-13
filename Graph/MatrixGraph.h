#include "MatrixWGraph.h"
#ifndef MatrixGraph_H
#define MatrixGraph_H

class MatrixGraph : public MatrixWGraph{
	public:
		MatrixGraph(int nodes);
		void InsertEdge(int u,int v) override;
		~MatrixGraph();
};
#include "MatrixGraph.cpp"
#endif
