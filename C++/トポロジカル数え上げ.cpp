int main() {
	  ll N,M;
    std::cin >> N>>M;
		ll k[N+1] = {};
		rep(i,0,M){
			ll a,b;
			std::cin >> a>>b;
			k[a-1] += 1<<(b-1);
		}
		ll dp[1<<N + 2] = {};
		dp[0] = 1;
		rep(i,0,1<<N){
			rep(j,0,N){
				if ((i&(1<<j)) == 0 && ((i&k[j])== 0)){
					dp[i | (1<<j)] += dp[i];
				}
			}
		}
		std::cout << dp[1<<N-1] << '\n';
}
