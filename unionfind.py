class UnionFind():
    def __init__(self,size):
        self.table = [-1 for _  in range(size)]
    def find(self,x):
        while self.table[x] >= 0:
            x = self.table[x]
        return x

    def union(self,x,y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            if self.table[s1] != self.table[s2]:
                if self.table[s1] < self.table[s2]:
                    self.table[s2] = s1
                else:
                    self.table[s1] = s2
            else:
                self.table[s1] += -1
                self.table[s2] = s1
        return

##強い
class UnionFind(object):

    def __init__(self, N):
        self.N = N
        self.parent = list(range(self.N))
        self.rank = [0] * self.N
        self.size = [1] * self.N

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            x, y = y, x

        self.size[x] += self.size[y]
        self.parent[y] = x
        if self.rank[x] == self.rank[y]:
            self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def count(self, x):
        return self.size[self.find(x)]
