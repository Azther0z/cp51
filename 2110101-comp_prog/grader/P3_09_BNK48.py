member={}
ota={}
while True:
	s=input().split()
	if len(s)==1:
		break
	s[0]=s[0].strip()
	s[1]=s[1].strip()
	s[2]=int(s[2])
	if s[1] not in member:
		member[s[1]]=[0,[],0]
	member[s[1]][0]+=s[2]
	member[s[1]][1].append(s[0])
	if s[0] not in ota:
		ota[s[0]]={}
	if s[1] not in ota[s[0]]:
		ota[s[0]][s[1]]=0
	ota[s[0]][s[1]]+=s[2]
if s[0]=='1':
	tmp=[]
	for i in member:
		tmp.append([i,member[i][0]])
	tmp.sort(key=lambda x:[-x[1],x[0]])
	print(f'{tmp[0][0]}, {tmp[1][0]}, {tmp[2][0]}')
if s[0]=='2':
	tmp=[]
	for i in member:
		tmp.append([i,len(set(member[i][1]))])
	tmp.sort(key=lambda x:[-x[1],x[0]])
	print(f'{tmp[0][0]}, {tmp[1][0]}, {tmp[2][0]}')
if s[0]=='3':
	for i in ota:
		tmp=[]
		for j in ota[i]:
			tmp.append([j,ota[i][j]])
		tmp.sort(key=lambda x:[-x[1],x[0]])
		#print(ota[i])
		kami=tmp[0][0]
		member[kami][2]+=1
	tmp=[]
	for i in member:
		tmp.append([i,member[i][2]])
	tmp.sort(key=lambda x:[-x[1],x[0]])
	print(f'{tmp[0][0]}, {tmp[1][0]}, {tmp[2][0]}')