def solve(x):
  if x>=10**9:
    tmp = str(round(x/(10**9),1))
    if len(tmp)>3:
      tmp = str(round(float(tmp)))
    return tmp+"B"
  if x>=10**6:
    tmp = str(round(x/(10**6),1))
    if len(tmp)>3:
      tmp = str(round(float(tmp)))
    return tmp+"M"
  if x>=10**3:
    tmp = str(round(x/(10**3),1))
    if len(tmp)>3:
      tmp = str(round(float(tmp)))
    return tmp+"K"
      
  return x
  
x = int(input())
print(solve(x))