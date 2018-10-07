N,M = map(int,input().split())
b = [0] * N
for i in range(M):
  c,d = map(int,input().split())
  b[c-1] += 1<<(d-1)
dp = [0] * (1 << N)
dp[0] = 1
# ノードIDと対応するビット位置は繰り返し求めるので事前計算しておく
jbs = [(j, 1 << j) for j in range(N)]

for i in range(1 << N):
    for j, jb in jbs:
        if (i & jb) == 0 and (i & b[j]) == 0:
            dp[i | jb] += dp[i]

print(dp[-1])
