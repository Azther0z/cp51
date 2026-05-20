grade = ['F','D','D+','C','C+','B','B+','A']
idarr = []
arr = []
while True:
	x = input().strip()
	if x=='q':
		break
	a,b = x.split()
	idarr.append(a)
	arr.append(b)
s = input().split()
for i in s:
	if i in idarr:
		idx = idarr.index(i)
		arr[idx] = grade[min(grade.index(arr[idx])+1,len(grade)-1)]
result = []
for i in range(len(idarr)):
	result.append([idarr[i],arr[i]])
result.sort()
for i in result:
	print(i[0],i[1])