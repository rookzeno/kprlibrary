from collections import deque
class BIT:
    def __init__(self, node_size):
        self._node = node_size+1
        self.bit = [0]*self._node

    def add(self, index, add_val):
        while index < self._node:
            self.bit[index] += add_val
            index += index & -index

    def sum(self, index):
        res = 0
        while index > 0:
            res += self.bit[index]
            index -= index & -index
        return res

s = input()
s2 = input()
n = len(s)
a = [ord(i) - ord("a") for i in s]
c = [ord(i) - ord("a") for i in s2]
d = {}
for i in range(26):
  d[i] = deque([])
for i in range(n):
  d[c[i]].append(i+1)
for i in range(n):
  x = d[a[i]].popleft()
  a[i] = x
b = []
for i in range(n):
  b.append([a[i],i+1])
b.sort()
b = b[::-1]
bit = BIT(n)
ans = 0
for i,j in b:
  bit.add(j,1)
  ans += bit.sum(j-1)
print(ans)
