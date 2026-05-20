a = float(input())
l=0
r=a
while abs(a-10**l)>1e-10*max(a,10**l):
	mid = l+(r-l)/2
	if 10**mid<=a:
		l=mid
	else:
		r=mid
print(round(l,6))