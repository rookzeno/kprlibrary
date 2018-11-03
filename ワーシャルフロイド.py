def warshall_floyd(n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


#abc74
n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
def Warshall_Floyd(edges,N):
  ans = 0
  for j in range(N):
    for i in range(N):
      flag = 0
      for k in range(N):
        if edges[i][j]> edges[i][k]+edges[k][j]:
          print(-1)
          exit()
        if (edges[i][k] + edges[k][j] == edges[i][j] and i != k and k != j):
          flag = 1
      if flag == 0:
        ans += edges[i][j]
  return edges,ans
x,ans = Warshall_Floyd(a,n)
print(ans//2)
