#include <vector>
#include <stack>
#include "../DisjoinUnionSet/DSU.h"
#include <utility>
#ifndef Graph_H
#define Graph_H

class Graph{
	public:
		Graph(int nodes);
		~Graph();
		bool IsEmtpy() const {
			return n == 0;
		}
		int NumberOfVertices() const{
			return n;
		}
		int NumberOfEdges() const{
			return e;
		}
		virtual std::vector<int> adjNodes(int u) = 0;
		virtual int Degree(int u) const =0;
		virtual bool ExistsEdge(int u,int v) =0;
		virtual void InsertEdge(int u,int v) =0;
		virtual void InsertEdge(int u,int v,double w) =0;
		virtual void DeleteVertex(int v) =0;
		virtual void DeleteEdge(int u,int v) =0;
		
		void DFS();
		void DFS(const int v);
		
		void BFS(int v);
		
		void Components();
		
		void DfnLow(const int x);
		void DfnLow(const int u,const int v);
		
		void Biconnected();
		void Biconnected(const int u,const int v);// ???
		
		// these three minimum spanning tree must be weight graph
		virtual double Kruskal() = 0;
		virtual double Prim(int n) = 0;
		virtual double Sollin() = 0;
		
		virtual void relax(int u,int v) = 0; //relaxation
		virtual void dijkstra(int source) = 0;
		virtual bool bellman_ford(int source) = 0;
		virtual void floyd_warshall() = 0;
		
		//Flow Networks是一個weighted,directed graph，其edge(X,Y)具有非負的capacity，c(X,Y) >= 0，如圖二(a)。
		//(此處以capacity取代weight，capacity就是「水管孔徑」。)
		// ref: https://alrightchiu.github.io/SecondRound/flow-networksmaximum-flow-ford-fulkerson-algorithm.html
		//maximum flow
		virtual double EdmondsKarp(int s,int t) = 0; // used for directed weight graph
		
		
		//virtual void topologySort(); // not a total order sort;
		
		int nodes; // nodes 表 目前 graph 最大上限的節點數量 
		DSU dsu;
		int n;     // n 表 目前有幾格點 已經紀錄 
		int e;
	private:
		std::stack<std::pair<int,int>> s;
		int num;
		int *dfn;
		int *low;
		bool *visited;
		
};
#include "Graph.cpp"
#endif
