s = input().split()
s[1] = s[1][2:]
mn = 1e9
mx = 0
summ = 0
count = 0
with open(s[0],'r') as f:
	for line in f:
		l = line.split()
		if l[0][0:2]==s[1]:
			mn = min(mn,float(l[1]))
			mx = max(mx,float(l[1]))
			summ += float(l[1])
			count += 1
if mn==1e9:
	print('No data')
else:
	print(mn,mx,summ/count)