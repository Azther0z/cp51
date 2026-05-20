arr = input().split()
a = []
for x in arr:
	a.append(int(x))
a.sort()
a.append(1e9)
unique = []
for i in range(len(a)-1):
	if a[i]!=a[i+1]:
		unique.append(a[i])
print(len(unique))
unique.sort()
print(unique[:10])