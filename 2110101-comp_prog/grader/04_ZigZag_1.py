mna = 1e9
mxa = -1e9
mnb = 1e9
mxb = -1e9

n = input()
i = 0
x = str(input().strip())

while (x!="Zig-Zag") and (x!="Zag-Zig"):
  #print(x)
  if i%2:
    a,b = x.split(' ')
  else:
    b,a = x.split(' ')
  a,b = int(a),int(b)
  mna = min(mna,a)
  mxa = max(mxa,a)
  mnb = min(mnb,b)
  mxb = max(mxb,b)
  x = str(input().strip())
  i += 1

if x=="Zig-Zag":
  print(mnb, mxa)
else:
  print(mna, mxb)