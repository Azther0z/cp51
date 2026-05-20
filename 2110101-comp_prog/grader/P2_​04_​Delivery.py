month = [31,28,31,30,31,30,31,31,30,31,30,31]
arr = []
deli = {'E':1,'Q':3,'N':7,'F':14}
while True:
	s = input().strip().split()
	if s[0]=='END':
		break
	d = int(s[2])
	m = int(s[3])
	y = int(s[4])
	if y<2558:
		print(f'Error: {s[0]} {s[1]} {d} {m} {y} --> Invalid year')
		continue
	if 1>m or m>12:
		print(f'Error: {s[0]} {s[1]} {d} {m} {y} --> Invalid month')
		continue
	if (y-543)%400==0 or ((y-543)%4==0 and (y-543)%100!=0):
		month[1] = 29
	else:
		month[1] = 28
	if 1>d or d>month[m-1]:
		print(f'Error: {s[0]} {s[1]} {d} {m} {y} --> Invalid date')
		continue
	if s[1] not in list(deli.keys()):
		print(f'Error: {s[0]} {s[1]} {d} {m} {y} --> Invalid delivery type')
		continue
	d += deli[s[1]]
	if d>month[m-1]:
		d -= month[m-1]
		m+= 1
	if m>12:
		m = 1
		y += 1
	arr.append([s[0],d,m,y])
arr.sort(key=lambda x:[x[3],x[2],x[1],x[0]])
for i in arr:
	print(f'{i[0]}: delivered on {i[1]}/{i[2]}/{i[3]}')
