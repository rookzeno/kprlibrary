int h,w,x;
int sh,sw,gh,gw;
char a[1002][1002];
int able[1002][1002] = {};
string s;
queue<pair<int,pair<int,int> > > que;
void dfs(int x,int y,int z){
  if (x+1 <= h-1 and a[x+1][y] == '.'){
    if (able[x+1][y] == -0){
      able[x+1][y] = z+1;
      que.push(make_pair((z+1),make_pair(x+1,y)));
    }
    }
    if (x-1 >= 0 and a[x-1][y] == '.'){
      if (able[x-1][y] == 0){
        able[x-1][y] = z+1;
        que.push(make_pair((z+1),make_pair(x-1,y)));
      }
      }
      if (y+1 <= w-1 and a[x][y+1] == '.'){
        if (able[x][y+1] ==0){
          able[x][y+1] = z+1;
          que.push(make_pair((z+1),make_pair(x,y+1)));
        }
        }
        if (y-1 >= 0 and a[x][y-1] == '.'){
          if (able[x][y-1] == 0){
            able[x][y-1] = z+1;
            que.push(make_pair((z+1),make_pair(x,y-1)));
          }
          }
}

signed main() {
	std::cin >> h>>w>>x;
  rep(i,0,h){
    std::cin >> s;
    rep(j,0,w){
      a[i][j] = s[j];
      if (s[j] == 'S'){
        sh = i;
        sw = j;
      }
      if (s[j] == 'G'){
        gh = i;
        gw = j;
        a[i][j] = '.';
      }
    }
  }
  rep(i,0,h){
    rep(j,0,w){
      if (a[i][j] == '#'){
        able[i][j] = -1;
      }
    }
  }
  que.push(make_pair(0,make_pair(sh,sw)));
  while(!que.empty()){
  pair<int,pair<int,int> > f  = que.front();
  que.pop();
    dfs(f.second.first,f.second.second,f.first);
  }
  if (able[gh][gw] <= 0){
    std::cout << -1 << '\n';
  }
  else{
  std::cout << able[gh][gw] << '\n';
}
}
