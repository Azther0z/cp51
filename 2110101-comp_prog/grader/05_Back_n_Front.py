def add(arr,x):
	if len(arr)%2==0:
		arr.append(x)
	else:
		arr = [x]+arr
	return arr
n = int(input())
arr = []
for i in range(n):
	arr = add(arr,int(input()))
for i in input().split():
	arr = add(arr,int(i))
while True:
	x = int(input())
	if x==-1:
		break
	arr = add(arr,x)
print(arr)