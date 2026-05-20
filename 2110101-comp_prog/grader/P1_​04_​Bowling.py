s = input().strip()
count = 0
frame = 1
score = []
tmp = []
for i in range(len(s)):
	if len(score)==9:
		if s[i]=='X':
			tmp.append(10)
		elif s[i]=='/':
			tmp.append(10-tmp[-1])
		else:
			tmp.append(int(s[i]))
	elif s[i]=='X':
		tmp.append(10)
		score.append(tmp)
		tmp=[]
	elif s[i]=='/':
		tmp.append(10-tmp[-1])
		score.append(tmp)
		tmp=[]
	else:
		tmp.append(int(s[i]))
		if(len(tmp)==2):
			score.append(tmp)
			tmp=[]
score.append(tmp)
def getNext(count,score,idx):
	result=0
	for i in score[idx:]:
		for j in i:
			result+=j
			count-=1
			if count==0:
				return result
	return 0
q = int(input().strip())
def getScore(q):
	result = 0
	if q==10:
		for i in score[-1]:
			result+=i
	else:
		for i in score[q-1]:
			if i==10:
				result+=10
				result+=getNext(2,score,q)
			else:
				result+=i
				if result==10:
					result+=getNext(1,score,q)
	return result
#print(len(score))
if 1<=q and q<=10:
	print(getScore(q))
else:
	result = 0
	for i in range(1,11):
		result+=getScore(i)
		#print(getScore(i))
	print(result)
