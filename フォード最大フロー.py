import sys
sys.setrecursionlimit(200000)
n,e = map(int,input().split())
g = [[] for i in range(n)]
for i in range(e):
  a,b,c = map(int,input().split())
  g[a].append([b,c,len(g[b])])
  g[b].append([a,0,len(g[a])-1])
def dfs(x,t,f):
  if x == t:
    return f
  global used
  used[x] = 1
  for j in range(len(g[x])):
    y, cap, rev = g[x][j]
    if cap and not used[y]:
      d = dfs(y,t,min(f,cap))
      if d:
        g[x][j][1] -= d
        g[y][rev][1] += d
        return d
  return 0

flow = 0
f = INF = float("inf")
while f:
  used = [0]*n
  f = dfs(0,n-1,INF)
  flow += f
  
print(flow)