filename=input()
k=int(input())
for i in range(k//10):
	print('-'*9,end='')
	print(i+1,end='')
print('-'*(k%10))
arr=[]
with open(filename,'r') as f:
	for i in f:
		for j in i.strip().split('.'):
			arr.append(j)
tmp=[]
for i in arr:
	if len(i)>=k:
		if len(tmp)!=0:
			print('.'.join(tmp).strip('.'))
			tmp=[]
		print(i)
	elif len('.'.join(tmp).strip('.'))+len(i)+1<=k:
		tmp.append(i)
	else:
		print('.'.join(tmp).strip('.'))
		tmp=[]
		tmp.append(i)
if len(tmp)!=0:
	print('.'.join(tmp).strip('.'))

