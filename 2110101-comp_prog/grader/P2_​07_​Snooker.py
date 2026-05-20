score = {'1':0,'2':0}
table = {'R':1,'Y':2,'G':3,'W':4,'B':5,'P':6,'K':7}
while True:
	tmp = input().strip()
	for j in tmp[1:]:
		if j!='X':
			score[tmp[0]]+=table[j]
	if len(tmp)==2 and tmp[1]=='K':
		break
print(f"{score['1']} {score['2']}")
if score['1']==score['2']:
	print('Tie')
if score['1']<score['2']:
	print('Player 2 wins')
if score['1']>score['2']:
	print('Player 1 wins')