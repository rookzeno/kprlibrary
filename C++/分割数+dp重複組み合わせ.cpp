dp[0][0] = 1;
for(int i = 1; i < 1005; i++) {
  for(int j = 0; j < 1005; j++) {
    if(j - i >= 0)
dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % mod;
    else dp[i][j] = dp[i-1][j];
  }
}

int a[MAX_N];
int dp[MAX_N+5][MAX_N+5];

for(int i = 0; i<= n; i++){
  dp[i][0]=1;
}
for(int i = 0; i<n;i++){
  for(int j=1; j<=m;j++){
    if(j-1-a[i]>=0){
      dp[i+1][j] = (dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+mod)%mod;
    }
    else{
      dp[i+1][j] = (dp[i+1][j-1] + dp[i][j])%mod;
    }
  }
}
