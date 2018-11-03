rep(i,0,h){
  std::cin >>s;
  rep(j,0,w){
    if (s[j] == '#'){
      c[i+j+1][i-j+300] = 1;
    }
  }
}
rep(i,1,h+w-1){
  rep(j,1,w+h-1){
    yoko[i][j] += yoko[i][j-1] + c[i][j];
    tate[i][j] += tate[i-1][j] + c[i][j];
  }
}
