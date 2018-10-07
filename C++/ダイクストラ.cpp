struct edge {
    int v;
    int w;
    int id;
    edge() {}
    edge(int v, int w, int id) : v(v), w(w), id(id) {};
};

vector<ll> dijkstra(int n, vector<vector<edge> >& G, int s) {
    vector<ll> d(n, 1ll<<55); d[s] = 0;
    priority_queue<pair<ll, int> > que;
    que.push(make_pair(0ll, s));
    while (!que.empty()) {
        auto p = que.top(); que.pop();
        int u = p.second;
        ll dist = -p.first;
        if (dist > d[u]) continue;
        for (edge e : G[u]) {
            if (d[e.v] > d[u]+e.w) {
                d[e.v] = d[u] + e.w;
                que.push(make_pair(-d[e.v], e.v));
            }
        }
    }
    return d;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<edge> > G(N);
	rep(i,0,M) {
		cin >> A[i] >> B[i] >> C[i];
		--A[i]; --B[i];
		G[A[i]].emplace_back(B[i], C[i], i);
		G[B[i]].emplace_back(A[i], C[i], i);
	}
auto d = dijkstra(N, G, i);
}
