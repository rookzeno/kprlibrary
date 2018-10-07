def comb(n,k,p):
  """power_funcを用いて(nCk) mod p を求める"""
  from math import factorial
  if n<0 or k<0 or n<k: return 0
  if n==0 or k==0: return 1
  a=factorial(n) %p
  b=factorial(k) %p
  c=factorial(n-k) %p
  return (a*pow(b,p-2,p)*pow(c,p-2,p))%p
"""
def power_func(a,b,p):
  """a^b mod p を求める"""
  if b==0: return 1
  if b%2==0:
    d=power_func(a,b//2,p)
    return d*d %p
  if b%2==1:
    return (a*power_func(a,b-1,p ))%p
"""

#別パターン 速い
mod = 998244353
fact = [1]*(n+k+1)
rfact = [1]*(n+k+1)
for i in range(n+k):
    fact[i+1] = rr = ((i+1) * fact[i]) % mod
    rfact[i+1] = pow(rr, mod-2, mod)
def comb(N, K,mod):
    return fact[N] * rfact[K] * rfact[N-K] % mod

#############
mod = 1000000007
fact = [1]*(n+10000+1)
rfact = [1]*(n+10000+1)
for i in range(n+10000):
    fact[i+1] = rr = ((i+1) * fact[i]) % mod
def comb(N, K,mod):
    return fact[N] * pow(fact[K], mod-2, mod) * pow(fact[N-K], mod-2, mod) % mod
