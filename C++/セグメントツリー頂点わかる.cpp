class SegmentTree {
  const static ll inf = (1LL << 60) - 1;
  int N, N0;
  ll data[4*200005][2];
 
public:
  SegmentTree(int N) {
    N0 = 1;
    while(N0 < N) N0 <<= 1;
    rep(j,0,2){
    rep(i, 0,2*N0+4) {data[i][j] = inf;}}
  }
 
  void update(int k, ll x,int y) {
    k += N0-1;
    data[k][0] = x;
    data[k][1] = y;
    while(k > 0) {
      k = (k - 1) / 2;
			if(data[2*k+1][0] > data[2*k+2][0]) {data[k][0] = data[2*k+2][0];data[k][1] = data[2*k+2][1];}
			else {data[k][0] = data[2*k+1][0];data[k][1] = data[2*k+1][1];}
    }
  }
 
  tuple<int,int> __query(int a, int b, int k, int l, int r) {
    if(a <= l && r <= b) {
      return forward_as_tuple(data[k][0],data[k][1]);
    }
    if(r <= a || b <= l) {
      return forward_as_tuple(inf,inf);
    }
		ll lv,lc,rv,rc;
    tie(lv,lc) = __query(a, b, 2*k+1, l, (l+r)/2);
    tie(rv,rc) = __query(a, b, 2*k+2, (l+r)/2, r);
		if (lv > rv) return forward_as_tuple(rv,rc);
		else return forward_as_tuple(lv,lc);
  }
 
  tuple<int,int> query(int a, int b) {
    return __query(a, b, 0, 0, N0);
  }
	void print() {
			rep(i,0,N0) cout << data[i][0] << " "<<data[i][1]<<" ";
			cout << endl;}
};


  SegmentTree STL(n);
	vector<pair<int, pair<int, int> > > kore;
	ll inf = (1LL << 60) - 1;
	rep(i,0,n){
		pair<int,int> c = a[i];
		ll hi1,hi2,mi1,mi2;
		tie(hi1,hi2) = STL.query(0,c.se);
		tie(mi1,mi2) = STR.query(c.se,n);
		if(hi2 != inf){kore.pb({b[c.se].fi + d*(-hi2+c.se)+b[hi2].fi,{c.se,hi2}});}
		if(mi2 != inf){kore.pb({b[c.se].fi + d*(mi2-c.se)+b[mi2].fi,{c.se,mi2}});}
		STL.update(c.se,c.fi+(n-c.se)*d,c.se);
		STR.update(c.se,c.fi+c.se*d,c.se);
	}

