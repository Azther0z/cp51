n = int(input().strip())
arr = []
vitamin = [0]*1000
mxvit = [[0,""]]*1000
for i in range(n):
	tmp = input().strip().split()
	for j in range(1,len(tmp)):
		tmp[j] = float(tmp[j])
		vitamin[j]+=tmp[j]
		if tmp[j]>mxvit[j][0]:
			mxvit[j]=[tmp[j],tmp[0]]
		elif tmp[j]==mxvit[j][0] and tmp[0]<mxvit[j][1]:
			mxvit[j]=[tmp[j],tmp[0]]
	arr.append(tmp)
op = input().strip().split()
if op[0]=="show":
	for i in arr:
		for j in i:
			print(j,end=' ')
		print()
if op[0]=="get":
	check = False
	for i in arr:
		if i[0]==op[1]:
			check = True
			for j in i:
				print(j,end=' ')
			break
	if not check:
		print(f"{op[1]} not found")
if op[0]=="avg":
	print(round(vitamin[int(op[1])]/n,4))
if op[0]=="max":
	print(f"{mxvit[int(op[1])][1]} {mxvit[int(op[1])][0]}")
if op[0]=="sort":
	arr.sort(key=lambda x:[x[int(op[1])],x[0]])
	for i in arr:
		print(i[0],end=' ')