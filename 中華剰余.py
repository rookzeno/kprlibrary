# 拡張ユークリッド
def extgcd(x, y):
    c0, c1 = x, y
    a0, a1 = 1, 0
    b0, b1 = 0, 1

    while c1 != 0:
        m = c0 % c1
        q = c0 // c1

        c0, c1 = c1, m
        a0, a1 = a1, (a0 - q * a1)
        b0, b1 = b1, (b0 - q * b1)

    return c0, a0, b0  # c0がgcd,(a0*x+b0*y=d=c0)


# 中国剰余定理
# BがあまりMがmod
# リターン値を (r, m) とすると解は x ≡ r (mod. m)m=lcm(M),r
# 解なしの場合は (0, -1) をリターン
def ChineseRem(B, M):
    r = 0
    m = 1
    for i in range(len(B)):
        d, p, q = extgcd(m, M[i])
        if (B[i] - r) % d != 0:
            return (0, -1)
        tmp = (((B[i] - r) // d) * p) % (M[i] // d)
        r += m * tmp
        m *= M[i] // d
    return (r % m, m)

a,a1 = map(int,input().split())
b,b1 = map(int,input().split())
c,c1 = map(int,input().split())
r, d = ChineseRem([a,b,c], [a1,b1,c1])
print(r,d)
