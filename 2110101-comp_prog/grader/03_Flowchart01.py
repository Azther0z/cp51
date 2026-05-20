a,b,c,d = input().split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
if a>b:
	tmp = a
	a = b
	b = tmp
	if d>=a:
		if c>d:
			c = c-a
	else:
		c = c+a
	b = a+c+d
else:
	if c>a and a>=b:
		d = d+a
	if d>c:
		b = b+2
	else:
		b = b*2
print(a,b,c,d)