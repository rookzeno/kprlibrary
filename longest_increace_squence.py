def LIS(L):
  from bisect import bisect
  seq=[]
  for i in L:
    pos=bisect(seq,i)
    if len(seq)<=pos:
      seq.append(i)
    else:
      seq[pos]=i
  return len(seq)
