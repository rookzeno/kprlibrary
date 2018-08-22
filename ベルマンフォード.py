def shortest_path(edge,num_v,start):
    inf = float("inf")
    d = [inf for f in range(num_v)]
    d[start] = 0;
    while True:
        update = False
        for e in edge:
            if d[e[0]] != inf and d[e[1]] > d[e[0]] + e[2]:
                d[e[1]] = d[e[0]] + e[2]
                update = True
        if not update:
            break
    return d
