SUM=0
n=0
x=''
while x!='q':
	x = input()
	if x=='q':
		break
	x = float(x)
	SUM+=x
	n+=1
if n==0:
	print('No Data')
else:
	print(round(SUM/n,2))