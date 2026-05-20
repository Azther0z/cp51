def solve():
	n=int(input())
	k=int(input())
	if not(1<=n) and not(1<=k and k<=100):
		print('Invalid n and k')
		return
	if not(1<=n):
		print('Invalid n')
		return
	if not(1<=k and k<=100):
		print('Invalid k')
		return
	for i in range(1,k+1):
		print(f'{i}',end='')
		if i==k:
			print('-'*(n-len(str(i))),end='')
		else:
			print('-'*(n-len(str(i))+1),end='')
	print()
	arr=['0','1']
	for i in range(n-1):
		arr+=arr[::-1]
		for j in range(0,len(arr)//2):
			arr[j]='0'+arr[j]
		for j in range(len(arr)//2,len(arr)):
			arr[j]='1'+arr[j]
	i=0
	while i<len(arr):
		for j in range(k):
			print(arr[i],end='')
			i+=1
			if i>=len(arr):
				break
			if j!=k-1:
				print(',',end='')
		print()
solve()