const int CMAX = 10000000;
long long fact[CMAX] = {};
long long revFact[CMAX] = {};
void setFact(int N)
{
  fact[0] = 1;
  for (int i = 1; i<N; i++)
  {
    fact[i] = fact[i-1]*i;
    fact[i] %= mod;
  }
  revFact[N-1] = powmod(fact[N-1],mod-2);
  for (int i=N-2;i>=0;i--)
  {
    revFact[i] = revFact[i+1]*(i+1);
    revFact[i] %= mod;
  }
}

long long getC(int a, int b)
{
  return (((fact[a] * revFact[b]) % mod) * revFact[a-b]) % mod;
}
