n=int(input())
count={}
for i in range(n):
	s=input().split()
	s=set(s)
	for j in s:
		j=int(j)
		if j not in count:
			count[j]=0
		count[j]+=1
union=0
intersect=0
for i in count:
	union+=1
	if count[i]==n:
		intersect+=1
print(union)
print(intersect)