def convex_polygon_area(p):
	SUM=0
	n=len(p)
	#p.sort(key=lambda x:[x[0],-x[1]])
	for i in range(n):
		SUM+=p[i][0]*p[(i+1)%n][1]
		SUM-=p[i][1]*p[(i+1)%n][0]
	return abs(SUM/2)
def is_heterogram(s):
	s = s.lower()
	arr = []
	for i in s:
		if 'a'>i or i>'z':
			continue
		if i not in arr:
			arr.append(i)
		else:
			return False
	return True 
def replace_ignorecase(s, a, b):
	current = 0
	result = ""
	while a.lower() in s.lower()[current:]:
		result += s[current:s.lower().find(a.lower(),current)]+b
		current = s.lower().find(a.lower(),current)+len(a)
		#print(result,current,s.lower()[current:])
	result+=s[current:]
	return result
def top3(votes):
	arr = []
	for v in votes.items():
		arr.append(v)
	arr.sort(key=lambda x:[-x[1],x[0]])
	result = []
	for i in arr[:3]:
		result.append(i[0])
	return result
for k in range(2):
	exec(input().strip())