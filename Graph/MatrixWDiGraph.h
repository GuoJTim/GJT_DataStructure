#include "Graph.h"
#include <vector>
#include <queue>
#ifndef MatrixWDigraph_H
#define MatrixWDigraph_H

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

class MatrixWDiGraph : public Graph{
	public:
		MatrixWDiGraph(int nodes);
		
		int Degree(int u) const override;
		bool ExistsEdge(int u,int v) override;
		void InsertEdge(int u,int v) override;
		void InsertEdge(int u,int v,double w) override;
		void DeleteVertex(int v) override;
		void DeleteEdge(int u,int v) override;
		std::vector<int> adjNodes(int u) override;
		~MatrixWDiGraph();
		double Kruskal() override;
		double Prim(int n) override;
		double Sollin() override;
		std::vector<std::vector<bool>> matrix;
		std::vector<std::vector<double>> weight;
		
		
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
#include "MatrixWDiGraph.cpp"
#endif
