text = []
with open(input().strip(),'r') as f:
	for line in f:
		text.append(line.strip())
if text[0]=='T2M':
	code = {}
	s = text[1].split('[')
	for i in s:
		if len(i)>0:
			code[i[0]] = i[2:]
	for i in text[2:]:
		check = True
		result = ""
		for j in i:
			if j in code:
				result+=code[j]+' '
			else:
				check = False
				break
		if check:
			print(result.strip())
		else:
			print(f'Invalid : {i}')
elif text[0]=='M2T':
	code = {}
	s = text[1].split('[')
	for i in s:
		if len(i)>0:
			code[i[2:]] = i[0]
	for i in text[2:]:
		check = True
		result = ""
		for j in i.split():
			if j in code:
				result+=code[j]
			else:
				check = False
				break
		if check:
			print(result.strip())
		else:
			print(f'Invalid : {i}')
else:
	print('Invalid code')