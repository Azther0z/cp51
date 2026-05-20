n = int(input())
arr = []
for i in range(n):
	x,y = input().split()
	x = float(x)
	y = float(y)
	arr.append([x*x+y*y,x,y,i+1])
arr.sort()
print(f'#{arr[2][3]}: ({arr[2][1]}, {arr[2][2]})')