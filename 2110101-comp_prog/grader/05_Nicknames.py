name = [['Robert','Dick'],
['William','Bill'],
['James','Jim'],
['John','Jack'],
['Margaret','Peggy'],
['Edward','Ed'],
['Sarah','Sally'],
['Andrew','Andy'],
['Anthony','Tony'],
['Deborah','Debbie'],]
n = int(input())
for i in range(n):
	x = input()
	check = False
	for j in name:
		if x==j[0]:
			print(j[1])
			check = True	
		if x==j[1]:
			print(j[0])
			check = True
	if not check:
		print('Not found')