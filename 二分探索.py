def cheak(x):
  if kai > x:
    return 0
  else:
    return 1
dai = max(a)
syo = 0
while True:
  if dai-syo <= 1:
    if cheak(dai) != 1:
          dai = syo
    break
  kon = (dai+syo)//2
  c = cheak(kon)
  if c == 1:
    dai = kon
  else:
    syo = kon
print(dai)
