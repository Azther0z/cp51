def solve():
	op = input().strip()
	n = int(input().strip())
	board = []
	for i in range(n):
		board.append(input().strip())
	m = len(board[0])
	for i in board:
		if m!=len(i):
			print('Invalid size')
			return 0
	if op=='90':
		result = []
		for j in range(m):
			tmp = ''
			for i in board[::-1]:
				tmp+=i[j]
			result.append(tmp)
		for i in result:
			print(i)
	if op=='180':
		result = []
		for i in board[::-1]:
			result.append(i[::-1])
		for i in result:
			print(i)
	if op=='flip':
		for i in board:
			print(i[::-1])
x = solve()	
