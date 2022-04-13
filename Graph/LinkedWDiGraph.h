#include "Graph.h"
#include "../Chain/Chain.h"
#include "../ChainIterator/ChainIterator.h"
#ifndef LinkedWDiGraph_H
#define LinkedWDiGraph_H
typedef struct node{
	int u;
	int v;
	double w;
};
struct comp{
    bool operator()(node a,node b){
        return a.w > b.w;
    }
};

class LinkedWDiGraph: public Graph{
	public:
		LinkedWDiGraph(int nodes);
		int Degree(int u) const override;
		bool ExistsEdge(int u,int v) override;
		void InsertEdge(int u,int v) override;
		void InsertEdge(int u,int v,double w) override;
		void DeleteVertex(int v) override;
		void DeleteEdge(int u,int v) override;
		int IndexOf(Chain<node> &chain,const int obj);
		std::vector<int> adjNodes(int u) override;
		double Kruskal() override;
		double Prim(int n) override;
		double Sollin() override;
		
		
		~LinkedWDiGraph();
		Chain<node> *adjLists;
};
#include "LinkedWDiGraph.cpp"
#endif
