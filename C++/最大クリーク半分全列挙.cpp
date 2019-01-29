//計算量 2^m/2 * m/2^2

signed main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	cin>>n>>m;
    vector<set<int>> g(n);
    rep(i,0,m){
        cin>>tmp>>tmp2;
        g[tmp2-1].insert(tmp-1);
        g[tmp-1].insert(tmp2-1);
    }
    int s1 = n/2;
    int s2 = n-s1;
    res = 0;
    VI S1(1<<s1), S2(1<<s2);
    rep(i,0,1<<s1){
        rep(j,0,s1){
            int x = i & (1<<j);
            if(x == 0){
                int z = 1;
                rep(k,0,s1){
                    if(i&(1<<k)){
                        
                        if(in(g[k],j)){
                            continue;
                        }
                        else{z = 0;break;}
                    }
                }
                S1[i|(1<<j)] = max(S1[i|(1<<j)],S1[i]+z);
            }
        }
    }
    rep(i,0,1<<s2){
        rep(j,0,s2){
            int x = i & (1<<j);
            if(x == 0){
                int z = 1;
                rep(k,0,s2){
                    if(i&(1<<k)){
                        
                        if(in(g[k+s1],j+s1)){
                            continue;
                        }
                        else{z = 0;break;}
                    }
                }
                S2[i|(1<<j)] = max(S2[i|(1<<j)],S2[i]+z);
                res = max(res,S2[i|(1<<j)]);
            }
        }
    }
    rep(i,0,1<<s1){
        if(S1[i]){
            VI d;
            rep(j,0,s1){
                if(i&(1<<j)){
                    d.pb(j);
                }
            }
            int x = 0;
            rep(j,0,s2){
                int z = 1;
                for(int k : d){
                    if(in(g[k],j+s1)){
                        continue;
                    }
                    else{z=0;break;}
                }
                if(z){x += 1<<j;}
            }
            res=max(res,S1[i]+S2[x]);
        }
    }
    cout<<res<<endl;
}
