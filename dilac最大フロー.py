from collections import deque
import sys
sys.setrecursionlimit(200000)
n,e = map(int,input().split())
g = [[] for i in range(n)]
for i in range(e):
  a,b,c = map(int,input().split())
  g[a].append([b,c,len(g[b])])
  g[b].append([a,0,len(g[a])-1])
   
def bfs(s,t):
  global level
  que = deque([s])
  level[s] = 0
  while que:
    v = que.popleft()
    lv = level[v] +1
    for y, cap, rev in g[v]:
      if cap and level[y] is None:
        level[y] = lv
        que.append(y)
  return level[t] if level[t] else 0
def dfs(x,t,f):
  if x == t:
    return f
  for j in range(it[x],len(g[x])):
    it[x] = j
    y, cap, rev = g[x][j]
    if cap and level[x] < level[y]:
      d = dfs(y,t,min(f,cap))
      if d:
        g[x][j][1] -= d
        g[y][rev][1] += d
        return d
  return 0
  
flow = 0
f = INF = float("inf")
level = [None]*n
while bfs(0,n-1):
  it = [0]* n
  f = INF
  while f:
    f = dfs(0,n-1,INF)
    flow += f
  level = [None]*n
print(flow)