def solve(x):
	arr = [0]*26
	for i in x.lower():
		if 'a'<= i and i<='z':
			arr[ord(i)-ord('a')]+=1
	return arr
a = input()
b = input()
if solve(a)==solve(b):
	print('YES')
else:
	print('NO')