n=int(input())
arr=[]
for i in range(n):
	a=input().strip()
	b=input().strip().split()
	arr.append([a,b])
while True:
	q=input().strip()
	if q=='-1':
		break
	mxScore=0
	result=''
	for i in arr:
		#print(i)
		blue=(1.0*i[1].count(q))/(1.0*len(i[1]))
		green=1.0/len(set(i[1]))
		score=blue*green
		#print(i[1].count(q),len(i[1]),blue,green)
		if mxScore<score:
			mxScore=score
			result=i[0]
	if mxScore==0:
		print('NOT FOUND')
	else:
		print(result)