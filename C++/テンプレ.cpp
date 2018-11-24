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
typedef vector<vector<int>> VVI;
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
int n;


signed main() {
	int N,M;
	std::cin >> N>>M;
	std::vector<std::vector<int>> g;
	rep(i,0,M){
		int l,r,d;
		scanf("%lld %lld %lld",&l,&r,&d);
		a--, b--;
		std::vector<int> v = {y, a, b};
		edges.emplace_back(v);
	}
	printf("%d",n);
}
//初期化
int a[100009]
for(i=0;i<(sizeof(a)/sizeof(a[0]));i++){
a[i]=-1;

//graph
vector <pair<int, int> >  g[100009];
rep(i,0,M){
	int l,r,d;
	scanf("%d %d %d",&l,&r,&d);
	l--, r--;
	g[l].push_back(make_pair(r, d));
	g[r].push_back(make_pair(l, -d));
}
}
