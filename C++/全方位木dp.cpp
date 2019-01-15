#include <bits/stdc++.h>
using namespace std;
#define int long long   // aaaaaaaaaaaaaaaaaa
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define SIZE(buff) (sizeof(buff)/sizeof(buff[0]))
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
template<typename T, typename U>ostream& operator << (ostream& os, pair<T, U>& pair_var)
{os << "(" << pair_var.first << ", " << pair_var.second << ")";return os;}
// head
int q,m,n,k,res,tmp,tmp2,tmp3;
//int a[200010] = {};
//int b[200010] = {};
int dist [100002];
deque<PII> que;
//int dp[305][305][305] = {};
string s;
vector<pair<int,int>> g[200010];

int dfs(int x , int y){
	for(auto i : g[x]){
		if (i.fi == y) continue;
		dfs(i.fi,x);
		dist[x] = max(dist[x],dist[i.fi]+i.se);
		}
}
int dfs2(int x, int d_par, int y)
{
  vector< pair< int, int > > d_child;
  d_child.emplace_back(0, -1); 
  for(auto i : g[x]) {
    if(i.fi == y) d_child.emplace_back(d_par + i.se, i.fi);
    else d_child.emplace_back(i.se + dist[i.fi], i.fi);
  }
  sort(d_child.rbegin(), d_child.rend());
  int ret = d_child[0].fi + d_child[1].fi; 
  for(auto i : g[x]) {
    if(i.fi == y) continue;
    ret = max(ret, dfs2(i.fi, d_child[d_child[0].se == i.fi].fi, x));
  }
  return (ret);
}

signed main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	std::cin >>n;
	rep(i,0,n-1){
		cin>>tmp>>tmp2>>tmp3;
		g[tmp].pb({tmp2,tmp3});
		g[tmp2].pb({tmp,tmp3});
	}
	dfs(0,-1);
	cout<<dfs2(0,0,-1)<<endl;

}

