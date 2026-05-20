n=int(input())
mp={}
for i in range(n):
	s=input().split(',')
	s[1]=s[1].strip()
	if s[1] not in mp:
		mp[s[1]]=[]
	mp[s[1]].append(s[0])
	s[2]=s[2].strip()
	if s[2] not in mp:
		mp[s[2]]=[]
	mp[s[2]].append(s[0])
q=input().split(',')
for i in q:
	i=i.strip()
	if i not in mp:
		print(f'{i} -> Not found')
	else:
		print(f'{i} -> {", ".join(mp[i])}')