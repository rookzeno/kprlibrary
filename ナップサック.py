from collections import defaultdict


N,W = map(int, input().split())
WV = []
for i in range(N):
    WV.append(list(map(int, input().split())))

dp = defaultdict(int)

dp[0] = 0

for w,v in WV:
    for new_w, new_v in list(dp.items()):
        if w + new_w <= W:
            dp[w + new_w] = max(dp[w + new_w], v + new_v)
print(dp)
