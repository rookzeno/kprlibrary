a = input()
n = len(a)
dp = [[[0 for j in range(2)] for k in range(2)] for i in range(n+1)]
dp[0][0][0] = 1
for i in range(n):
  for j in range(2):
    for k in range(2):
      lim = 9 if j else int(a[i]) - 0
      for d in range(lim+1):
        dp[i+1][(j or d) <lim][(k == 1 or d == 3)] += dp[i][j][k]
ans = 0
for j in range(2):
  ans += dp[n][j][1]
print(ans)
print(dp)
