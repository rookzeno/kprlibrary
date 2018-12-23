n,k = map(int,input().split())
dpw = [[0]*(4*k+1) for i in range(4*k+1)]
for i in range(n):
  x,y,c = map(str,input().split())
  x = int(x)
  y = int(y)
  if c == "W":
    dpw[x%(2*k)+1][y%(2*k)+1] += 1
    dpw[x%(2*k)+2*k+1][y%(2*k)+2*k+1] += 1
    dpw[x%(2*k)+2*k+1][y%(2*k)+1] += 1
    dpw[x%(2*k)+1][y%(2*k)+2*k+1] += 1
  else:
    y+=k
    dpw[x%(2*k)+1][y%(2*k)+1] += 1
    dpw[x%(2*k)+2*k+1][y%(2*k)+2*k+1] += 1
    dpw[x%(2*k)+2*k+1][y%(2*k)+1] += 1
    dpw[x%(2*k)+1][y%(2*k)+2*k+1] += 1
for i in range(1,4*k+1):
  for j in range(1,4*k+1):
    dpw[i][j] += dpw[i-1][j] + dpw[i][j-1]-dpw[i-1][j-1]
ans = 0
for i in range(1,2*k+1):
  for j in range(1,2*k+1):
    tmp = 0
    tmp += dpw[k+i-1][k+j-1]+dpw[i-1][j-1]-dpw[i-1][j+k-1]-dpw[i+k-1][j-1]
    tmp += dpw[k+i-1+k][k+j-1+k]+dpw[i-1+k][j-1+k]-dpw[i-1+k][j+k-1+k]-dpw[i+k-1+k][j-1+k]
    ans = max(ans,tmp)
print(ans)
