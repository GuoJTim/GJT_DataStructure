#include "LinkedWDiGraph.h"
#ifndef LinkedWGraph_H
#define LinkedWGraph_H

class LinkedWGraph : public LinkedWDiGraph{
	public:
		LinkedWGraph(int nodes);
		void InsertEdge(int u,int v) override;
		void InsertEdge(int u,int v,double w) override;
		double Kruskal() override;
		double Prim(int n) override;
		double Sollin() override;
		void DeleteEdge(int u,int v) override;
		~LinkedWGraph();
		
};
#include "LinkedWGraph.cpp"
#endif
