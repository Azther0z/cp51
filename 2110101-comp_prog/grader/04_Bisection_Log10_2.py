a = float(input().strip())
L = 0
U = 0
tmp = a
while tmp>0:
	tmp//=10
	U+=1
while abs(a-10**L)>1e-10*max(a,10**L):
	mid = L+(U-L)/2
	if 10**mid < a:
		L = mid
	else:
		U = mid
print(round(L,6))
