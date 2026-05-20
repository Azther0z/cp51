n=int(input())
mp={}
mpp={}
bidder=[]
for i in range(n):
	s=input().split()
	if s[0]=='B':
		if s[1] not in mpp:
			mpp[s[1]]=[]
		if s[1] not in bidder:
			bidder.append(s[1])
		if s[2] not in mp:
			mp[s[2]]={}
		mp[s[2]][s[1]]=[int(s[3]),i]
	else:
		if s[1] in mp[s[2]]:
			mp[s[2]].pop(s[1])
for i in mp:
	tmp=[]
	for j in mp[i]:
		tmp.append([j,mp[i][j][0],mp[i][j][1]])
	tmp.sort(key=lambda x:[-x[1],x[2]])
	if len(tmp)==0:
		continue
	winner=tmp[0]
	mpp[winner[0]].append([winner[1],i])
	#print(i,mp[i])
bidder.sort()
for i in bidder:
	total=0
	tmp=[]
	for j in mpp[i]:
		total+=int(j[0])
		tmp.append(j[1])
	tmp.sort()
	if total==0:
		print(f'{i}: ${total}')
	else:
		print(f'{i}: ${total} -> {" ".join(tmp)}')