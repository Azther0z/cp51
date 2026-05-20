def solve(row,col):
	#print(row,col)
	checkRow=len(row)==1
	if not('a'<=row and row<='z'):
		checkRow=False
	checkCol=len(col)!=0
	for i in col:
		if not('0'<=i and i<='9'):
			checkCol=False
			break
	if checkCol and not(1<=int(col) and int(col)<=52):
		checkCol=False
	if not(checkRow) and not(checkCol):
		print('Invalid row and column')
		return
	if not(checkRow):
		print('Invalid row')
		return
	if not(checkCol):
		print('Invalid column')
		return
	col=int(col)
	if (ord(row[0])-ord('a'))%2==0 and col%2==1:
		print('White')
		return
	if (ord(row[0])-ord('a'))%2==1 and col%2==1:
		print('Black')
		return
	if (ord(row[0])-ord('a'))%2==0 and col%2==0:
		print('Black')
		return
	if (ord(row[0])-ord('a'))%2==1 and col%2==0:
		print('White')
		return
s=input().strip()
row=col=''
if len(s)<=3:
	row=s[0].lower().strip()
	col=s[1:].strip()
else:
	ss=s.split(',')
	if 'row' in ss[1]:
		ss[0],ss[1]=ss[1],ss[0]
	row=ss[0][ss[0].find('=')+1:].lower().strip()
	col=ss[1][ss[1].find('=')+1:].strip()
solve(row,col)