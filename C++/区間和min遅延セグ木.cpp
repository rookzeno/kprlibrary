struct starry_sky_tree {
    int size;
    vector<int> data;
    vector<int> lazy;
    vector<int> width;

    starry_sky_tree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        data.resize(size*2, 0);
        lazy.resize(size*2, 0);
        width.resize(size*2, 1);
        for (int i = size-2; i >= 0; i--) {
            width[i] = width[i*2+1] + width[i*2+2];
        }
    }

    void lazy_propagate(int p) {
        data[p] += lazy[p];
        if (p < size-1) {
            lazy[p*2+1] += lazy[p];
            lazy[p*2+2] += lazy[p];
        }
        lazy[p] = 0;
    }

    void add(int wishl, int wishr, int x) {
        add(wishl, wishr, 0, size, 0, x);
    }
    void add(int wishl, int wishr, int watchl, int watchr, int k, int x) {
        if (wishr <= watchl || watchr <= wishl) {
            lazy_propagate(k);
            return;
        }
        if (wishl <= watchl && watchr <= wishr) {
            lazy[k] += x;
            lazy_propagate(k);
            return;
        }

        int mid = (watchl + watchr) / 2;
        lazy_propagate(k);
        add(wishl, wishr, watchl, mid, k*2+1, x);
        add(wishl, wishr, mid, watchr, k*2+2, x);
        data[k] = min(data[k*2+1], data[k*2+2]);
    }

    int getmin(int wishl, int wishr) {
        return getmin(wishl, wishr, 0, size, 0);
    }
    int getmin(int wishl, int wishr, int watchl, int watchr, int k) {
        if (wishr <= watchl || watchr <= wishl) return 1LL<<60;
        if (wishl <= watchl && watchr <= wishr) {
            lazy_propagate(k);
            return data[k];
        }

        int mid = (watchl + watchr) / 2;
        int L = getmin(wishl, wishr, watchl, mid, k*2+1);
        int R = getmin(wishl, wishr, mid, watchr, k*2+2);
        return min(L, R);
    }
};




signed main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	 scanf("%lld %lld", &n,&m);
    rep(i,0,n){
        scanf("%lld", &a[i]);
    }
    rep(i,0,m){
        scanf("%lld %lld", &tmp,&tmp2);
        kukan.pb({tmp-1,tmp2-1});
    }
    starry_sky_tree sst(n+2);
    rep(j,0,n){
         sst.add(j,j+1,a[j]);
    }
    int best1 = -1;
    int best2 = -1;
    VI best3;
    VI tm3;
    int tm2 = 0;
    int used[301] = {};
    rep(i,0,n){
        int tm1 = a[i];
        
    rep(k,0,m){
         PII j = kukan[k];
         if (used[k]) continue;
         if (j.fi <= i && j.se >= i)continue;
         sst.add(j.fi,j.se+1,-1);
         tm2 += 1;
         tm3.pb(k);
         used[k] = 1;
        }
    tm1 -= sst.getmin(0,n);
    if (best1 < tm1) {
        best1 = tm1;
        best2 = tm2;
        best3.clear();
        for (auto o: tm3){
            best3.pb(o);
        }
    }
    VI nuku;
    rep(jj,0,tm3.size()){
         k = tm3[jj];
         PII j = kukan[k];
         if (j.fi == i+1 || j.se == i+1){
             sst.add(j.fi,j.se+1,1);
         used[k]=0;
         tm2 -=1;
         nuku.pb(jj);
    }}
    sort(allr(nuku));
    rep(jjj,0,nuku.size()){tm3.erase(tm3.begin()+nuku[jjj]);}
    }
    cout << best1<<"\n";
    cout << best2<<"\n";
    rep(i,0,best3.size()){
        cout<<best3[i]+1<<" ";
    }
    cout<<"\n";
}
