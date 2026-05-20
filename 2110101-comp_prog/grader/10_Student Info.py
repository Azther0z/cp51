n=int(input())
arr=[]
for i in range(n):
	s=input().split()
	arr.append([s[0],s[1:]])
q=input().split()
result=[]
for i in arr:
	check=True
	for j in q:
		if j not in i[1]:
			check=False
			break
	if check:
		result.append([i[0]]+i[1])
result.sort()
if len(result)==0:
	print('Not Found')
for i in result:
	for j in i:
		print(j,end=' ')
	print()