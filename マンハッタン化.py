H, W = map(int, input().split())
grid = []
for i in range(H):
    grid.append(list(input()))

res = 0
# cross
cross_posi = [[0]*(H+W-1) for _ in range(H+W-1)]
for i in range(H):
    for j in range(W):
        if grid[i][j] == "#":
            cross_posi[i+j][i-j+W-1] = 1
# pre-compute
cross_posi_1 = [[0]*(H+W) for _ in range(H+W-1)]
for i in range(H+W-1):
    r = 0
    for j in range(H+W-1):
        r += cross_posi[i][j]
        cross_posi_1[i][j+1] = r

cross_posi_2 = [[0]*(H+W) for _ in range(H+W-1)]
for i in range(H+W-1):
    r = 0
    for j in range(H+W-1):
        r += cross_posi[j][i]
        cross_posi_2[i][j+1] = r
