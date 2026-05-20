while True:
	s = input()
	if s=='end':
		break
	for i in s:
		if 'a'<=i and i<='z':
			print(chr((ord(i)-ord('a')+13)%26+ord('a')),end='')
		elif 'A'<=i and i<='Z':
			print(chr((ord(i)-ord('A')+13)%26+ord('A')),end='')
		else:
			print(i,end='')
	print()