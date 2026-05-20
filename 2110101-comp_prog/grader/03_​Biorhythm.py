month = [0,31,0,31,30,31,30,31,31,30,31,30,31]
bd, bm, by, d, m, y = [int(e) for e in input().split()]
by-=543
y-=543

if (by%4==0 and by%100!=0)or by%400==0:
	month[2]=29
else:
	month[2]=28

a = month[bm]-bd+1
#print(a)
for i in range(bm+1,13):
	a+=month[i]

#print(a)

if (y%4==0 and y%100!=0) or y%400==0:
	month[2]=29
else:
	month[2]=28

b = d-1
for i in range(1,m):
	b+=month[i]

#print(b)
import math
x = a+b+(y-by-1)*365
i = math.sin((2*math.pi*x)/23)
j = math.sin((2*math.pi*x)/28)
k = math.sin((2*math.pi*x)/33)
print(x, "{:.2f}".format(i),"{:.2f}".format(j),"{:.2f}".format(k) )