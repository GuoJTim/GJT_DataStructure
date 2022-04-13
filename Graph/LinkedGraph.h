#include "LinkedDiGraph.h"
#include "../Chain/Chain.h"
#include "../ChainIterator/ChainIterator.h"
#ifndef LinkedGraph_H
#define LinkedGraph_H

class LinkedGraph: public LinkedDiGraph{
	public:
		LinkedGraph(int nodes);
		void InsertEdge(int u,int v) override;
		void InsertEdge(int u,int v,double w) override;
		void DeleteEdge(int u,int v) override;
		~LinkedGraph();
};
#include "LinkedGraph.cpp"
#endif
