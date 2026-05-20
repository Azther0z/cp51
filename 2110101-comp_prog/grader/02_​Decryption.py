s = input()
a = s[3::7]
b = s[7::5]
c = str(int(a)+int(b)+10000)
d = c[-4]+c[-3]+c[-2]
e = str(int(d[0])+int(d[1])+int(d[2]))
#print(e)
e = int(e[-1])+1
print(d+chr(64+e))