n = int(input())
arr = []
tmp = []
current = 0
time = 0
count = 0
for i in range(n):
	s = input().split()
	if s[0]=='reset':
		current = int(s[1])
	elif s[0]=='new':
		arr.append([int(s[1]),current])
		print(f'ticket {current}')
		current += 1
	elif s[0]=='next':
		print(f'call {arr[0][1]}')
		tmp = arr[0]
		arr.pop(0)
	elif s[0]=='order':
		print(f'qtime {tmp[1]} {int(s[1])-tmp[0]}')
		time += int(s[1])-tmp[0]
		count += 1
	elif s[0]=='avg_qtime':
		print(f'avg_qtime {round(time/count,4)}')