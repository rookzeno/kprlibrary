from collections import deque
import sys
h,w = map(int,input().split())
a = [[j for j in input()] for i in range(h)]
q= deque()
def dfs(x,y,e,f):
    i = 1
    k = []
    kb = []
    if (x+i <= n-1 and a[x+i][y] == "."):
        if e+f > able[x+i][y]:
            able[x+i][y] = e+f
            q.append([x+i,y,e,f])
    if (x-i>=0 and a[x-i][y] == "."):
        if e+f > able[x-i][y]:
            able[x-i][y] = e+f
            q.append([x-i,y,e,f])
    if (y+1 <= m-1 and f>= 1 and a[x][y+1] == "."):
        if e+f-1>able[x][y+1]:
            able[x][y+1] = e+f-1
            q.append([x,y+1,e,f-1])
    if (y-1 >= 0 and e>= 1 and a[x][y-1] == "."):
        if e+f-1>able[x][y-1]:
            able[x][y-1] = e+f-1
            q.append([x,y-1,e-1,f])
dfs(r,c,x,y)
while q:
    way = q.popleft()
    dfs(way[0],way[1],way[2],way[3])


#queなしの遅い

import sys
sys.setrecursionlimit(200000)
#input = sys.stdin.readline
h,w = map(int,input().split())
a = [[j for j in input()] for i in range(h)]
used = [[0]*w for i in range(h)]
def dfs(x,y):
    if used[x][y]:
        return 0
    global go
    used[x][y] = 1
    if x-1 >=0 and a[x-1][y] != a[x][y]:
            go.add((x-1,y))
            dfs(x-1,y)
    if y-1 >=0 and a[x][y-1] != a[x][y]:
            go.add((x,y-1))
            dfs(x,y-1)
    if x+1 <h and a[x+1][y] != a[x][y]:
            go.add((x+1,y))      
            dfs(x+1,y)
    if y+1 <w and a[x][y+1] != a[x][y]:
            go.add((x,y+1))
            dfs(x,y+1)
ans = 0
for i in range(h):
    for j in range(w):
        go = set()
        if used[i][j]:
            continue
        dfs(i,j)