
class Graph{
	public:
		int nodes;
		vector<int> graph[1000];
		Graph(int nodes){
			this->nodes = nodes+1;
			at_line.resize(nodes,0);
		}
		void link(int u,int v,int line){
			graph[u].pb(v);
			graph[v].pb(u);
		}

		void BFS(int from){//return avg
			queue<pair<int,int> > q;
			q.push(mp(from,0));
			bool visited[nodes];
			while(q.size()){
				pair<int,int> fr = q.front();q.pop();
				int u = fr.first;
				if (visited[u]) continue;
				
				for (int v: graph[u]){
					if(!visited[v]){
						q.push(mp(v,cnt+1));
						visited[v] = true;
					}
				}
			}
		}
};
