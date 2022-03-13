
class edge{
	public:
		int u,v;
		int weight;
		edge(int u,int v,int weight){
			this->u = u;
			this->v = v;
			this->weight = weight;
		}
};
bool comp(edge &a, edge &b){
	return a.weight < b.weight;
}


class graph{
	public:
		vector<int> parent;
		vector<int> size;
		graph(int nodes){
			parent.resize(nodes+1);
			for(int i = 0 ; i < nodes+1 ; i++){
				parent[i] = i;
			}
			size.resize(nodes,1);
		}
		
		int find(int index){
			if (parent[index] == index) return index;
			return parent[index] = find(parent[index]);	
		}

		void Union(int a,int b){
			int fa = find(a),fb = find(b);
			if (size[fb] > size[fa]) swap(fa,fb);
			size[fa] += size[fb];
			parent[fb] = fa;
		}

		lld kruskal(vector<edge> &g){
			lld weight = 0;
			sort(g.begin(),g.end(),comp);
			for(edge k : g){
				if (find(k.u) != find(k.v)){
					Union(k.u,k.v);
					weight += k.weight;
				}else{
					weight += k.weight;
				}
			}
			return weight;
		}
};

