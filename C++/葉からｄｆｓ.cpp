int q,m,n,k,res,tmp,tmp2;
int a[16][16] = {};
int b[200010] = {};
VVI g(100010);
VVI g2(100010);
deque<PII> que;
int dp[100010][3];
int hukasa[100010];
string s;
 
int dfs(int x , int y){
	for(auto i : g[x]){
		if (hukasa[i] > y+1){
			hukasa[i] = y+1;
			que.pb({i,y+1});
			g2[x].pb(i);
		}
	}
}
 
signed main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	std::cin >>n;
	rep(i,0,n-1){
		cin>>tmp>>tmp2;
		tmp--;tmp2--;
		g[tmp].pb(tmp2);
		g[tmp2].pb(tmp);
	}
	rep(i,0,n){
		hukasa[i] = 1<<30;
	}
	hukasa[0] = 0;
	que.pb({0,0});
	while(que.size()){
		PII ima = que.front();
		que.pop_front();
		dfs(ima.first,ima.second);
	}
	vector <PII> vec;
	rep(i,0,n){
	vec.pb({hukasa[i],i});
	}
	sort(vec.begin(), vec.end(), greater<PII>());
	for(auto x : vec){
		if (g2[x.se].size()== 0){
			dp[x.se][0] = dp[x.se][1] = 1;
			continue;
		}
		tmp = 1;
		tmp2 = 1;
		for(auto k : g2[x.se]){
			tmp *= dp[k][0];
			tmp2 *= (dp[k][0] + dp[k][1]);
			tmp %=mod;
			tmp2 %= mod;
		}
		dp[x.se][1] = tmp;
		dp[x.se][0] = tmp2;
	}
	cout<<(dp[0][0] + dp[0][1])%mod<<endl;
}