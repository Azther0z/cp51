def solve(x):
	arr = []
	with open(x,'r') as f:
		for line in f:
			arr.append(line.split())
	return arr
arr = []
s = input().split()
arr += solve(s[0])
arr += solve(s[1])
arr.sort(key=lambda x:[x[0][8:],x[0][0:7]])
for i in arr:
	print(i[0],i[1])