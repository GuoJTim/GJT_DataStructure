#include "Graph.h"
#include "../Chain/Chain.h"
#include "../ChainIterator/ChainIterator.h"

#ifndef DiGraph_MACRO

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

#define DiGraph_MACRO
#endif

#ifndef LinkedWDiGraph_H
#define LinkedWDiGraph_H

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
		
		void relax(int u,int v) override;
		void dijkstra(int source) override;
		bool bellman_ford(int source) override;
		void floyd_warshall() override;
	private:
		void initialize_single_source(int source); // ��l�� 
		int *dist; // to current dist 
		int *parent; // last path
		int ***D; // used for floyd-warshall
		int ***PI;// used for floyd-warshall
};
#include "LinkedWDiGraph.cpp"
#endif
