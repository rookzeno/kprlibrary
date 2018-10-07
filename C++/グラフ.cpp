struct edge { int to, cap, rev, cost; };
vector<edge> G[MAX_V];
void add_edge(int from, int to, int cap, int cost = 0){
	G[from].push_back(edge{ to, cap, (int)G[to].size(),cost });
	G[to].push_back(edge{ from,0,(int)G[from].size() - 1,-cost });
}
