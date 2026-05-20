def left(txt):
	while True:
		for i in range(len(txt)):
			if txt[i][0]!='.':
				return
		for i in range(len(txt)):
			txt[i]=txt[i][1:]
def right(txt):
	while True:
		for i in range(len(txt)):
			if txt[i][-1]!='.':
				return
		for i in range(len(txt)):
			txt[i]=txt[i][0:-1]
def all(txt):
	arr=[]
	n=len(txt)
	m=len(txt[0])
	for j in range(m):
		check=True
		for i in range(n):
			if txt[i][j]!='.':
				check=False
				break
		if check:
			arr.append(j)
	for i in range(n):
		tmp=''
		for j in range(m):
			if j not in arr:
				tmp+=txt[i][j]
		txt[i]=tmp
def display(txt):
	for i in txt:
		print(i)
filename=input().strip()
op=input().strip()
txt=[]
with open(filename) as f:
	for i in f:
		txt.append(i.strip())
if op=='LSTRIP':
	left(txt)
	display(txt)
elif op=='RSTRIP':
	right(txt)
	display(txt)
elif op=='STRIP':
	left(txt)
	right(txt)
	display(txt)
elif op=='STRIP_ALL':
	all(txt)
	display(txt)
else:
	print('Invalid command')
