import bisect
def press(a):
    n = len(a)
    b = set(a)
    b = list(b)
    b.sort()
    c = [0] * n
    for i in range(n):
        c[i] = bisect.bisect_left(b,a[i])
    return b,c
