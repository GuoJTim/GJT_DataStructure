#include "MatrixWDiGraph.h"
#ifndef MatrixWGraph_H
#define MatrixWGraph_H

class MatrixWGraph : public MatrixWDiGraph{
	public:
		MatrixWGraph(int nodes);
		void InsertEdge(int u,int v) override;
		void InsertEdge(int u,int v,double w) override;
		void DeleteEdge(int u,int v) override;
		double Kruskal() override;
		double Prim(int n) override;
		double Sollin() override;
		~MatrixWGraph();
};
#include "MatrixWGraph.cpp"
#endif
