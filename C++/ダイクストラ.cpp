vector<ll> dijkstra(ll n, vector<pair<ll,ll> >* G, ll s) {
    vector<ll> d(n, 1ll<<55); d[s] = 0;
    priority_queue<pair<ll, ll> > que;
    que.push(make_pair(0ll, s));
    while (!que.empty()) {
			auto p = que.top();que.pop();
			ll prov_cost = p.first;
			ll src = p.second;
			if(d[src]<prov_cost) continue;
			rep(i,0,g[src].size()){
				ll dest = g[src][i].first;
				ll weight = g[src][i].second;
				if ((d[dest] > d[src] + weight)){
					d[dest] = d[src] + weight;
					que.push({-d[dest],dest});
				}
			}
		}
    return d;
}

signed main() {
	std::cin >>n>>m>>s;
	rep(i,0,m){
		std::cin >> a[i]>>b[i]>>c[i];
//		b[i]--,a[i]--;
		g[a[i]].pb(mp(b[i], c[i]));
//		g[b[i]].pb(mp(a[i], c[i]));
	}
	vector<ll> d = dijkstra(n, g, s);
	rep(i,0,n){
		if(d[i] != 1LL<<55){
		std::cout << d[i] << '\n';
	}
	else{
		std::cout << "INF" << '\n';
	}
	}
}

signed main() {
	std::cin >>n>>m>>s;
	rep(i,0,m){
		std::cin >> a[i]>>b[i]>>c[i];
//		b[i]--,a[i]--;
		g[a[i]].pb(mp(b[i], c[i]));
//		g[b[i]].pb(mp(a[i], c[i]));
	}
	int d[100005];
	rep(i,0,n) d[i] = 1LL<<50;
	d[s] = 0;
	pque.push({0,s});
	while (!pque.empty()){
		PII p = pque.top();pque.pop();
		int prov_cost = p.first;
		int src = p.second;
		if(d[src]<prov_cost) continue;
		rep(i,0,g[src].size()){
			int dest = g[src][i].first;
			int weight = g[src][i].second;
			if ((d[dest] > d[src] + weight)){
				d[dest] = d[src] + weight;
				pque.push({-d[dest],dest});
			}
		}
	}
	rep(i,0,n){
		if(d[i] != 1LL<<50){
		std::cout << d[i] << '\n';
	}
	else{
		std::cout << "INF" << '\n';
	}
	}
}




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
