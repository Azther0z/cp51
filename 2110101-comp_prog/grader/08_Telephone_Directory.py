n = int(input().strip())
mp1 = {}
mp2 = {}
for i in range(n):
	s = input().strip().split()
	number = s[-1]
	name = " ".join(s[:-1])
	mp1[name] = number
	mp2[number] = name
m = int(input().strip())
for i in range(m):
	s = input().strip()
	if s in mp1:
		print(f"{s} --> {mp1[s]}")
	elif s in mp2:
		print(f"{s} --> {mp2[s]}")
	else:
		print(f"{s} --> Not found")