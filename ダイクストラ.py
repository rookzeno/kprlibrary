n = int(input())
p = []
for i in range(n):
    p.append(list(map(int, input().split())))




import heapq

def shortest_path(edge,num_v,start):
    inf = float("inf")
    cost = [[] for i in range(n+1)]
    for path in edge:
      cost[path[0]].append((path[1],path[2]))
      cost[path[1]].append((path[0],path[2]))
    d = [inf for j in range(num_v)]
    q = []
    heapq.heappush(q, (0, start))
    d[start] = 0
    while len(q) != 0:
      prov_cost, src = heapq.heappop(q)
      if d[src] < prov_cost:
                continue
      for dest,weight in cost[src]:
        if weight != float('inf') and d[dest] > d[src] + weight:
          d[dest] = d[src] + weight
          heapq.heappush(q, (d[dest], dest))
    return d
