import math
def so(k):
    n = True
    if k % 2 == 0 and k != 2:
      return False
    for divisor in range(2, math.floor(math.sqrt(k))+1):
      if k % divisor == 0:
        n = False
    return n
