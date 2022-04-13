#include "MatrixWDiGraph.h"
#ifndef MatrixDiGraph_H
#define MatrixDiGraph_H

class MatrixDiGraph : public MatrixWDiGraph{
	public:
		MatrixDiGraph(int nodes);
		void InsertEdge(int u,int v) override;
		~MatrixDiGraph();
};
#include "MatrixDiGraph.cpp"
#endif
