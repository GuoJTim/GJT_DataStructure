#include "Graph.h"
#include <vector>
#include "../Chain/Chain.h"
#include "../ChainIterator/ChainIterator.h"
#ifndef LinkedDiGraph_H
#define LinkedDiGraph_H

class LinkedDiGraph: public Graph{
	public:
		LinkedDiGraph(int nodes);
		int Degree(int u) const override;
		bool ExistsEdge(int u,int v) override;
		void InsertEdge(int u,int v) override;
		void InsertEdge(int u,int v,double w) override;
		void DeleteVertex(int v) override;
		void DeleteEdge(int u,int v) override;
		int IndexOf(Chain<int> &chain,const int obj);
		std::vector<int> adjNodes(int u) override;
		double Kruskal() override{
			cout << "min cost spanning tree must be weighted!" << endl;
		}
		double Prim(int n) override{
			cout << "min cost spanning tree must be weighted!" << endl;
		}
		double Sollin() override{
			cout << "min cost spanning tree must be weighted!" << endl;
		}
		~LinkedDiGraph();
		Chain<int> *adjLists;
};
#include "LinkedDiGraph.cpp"
#endif
