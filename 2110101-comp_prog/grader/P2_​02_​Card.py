number = {'A':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'T':10,'J':11,'Q':12,'K':13}
color = {'C':1,'D':2,'H':3,'S':4}
s = input().strip()
for i in range(0,len(s)-2,2):
	a = s[i:i+2]
	b = s[i+2:i+4]
	na = number[a[0]]
	nb = number[b[0]]
	ca = color[a[1]]
	cb = color[b[1]]
	if na != nb:
		if na>nb:
			print(f'+{abs(na-nb)}',end='')
		if na<nb:
			print(f'-{abs(na-nb)}',end='')
	elif ca != cb:
		if ca>cb:
			print(f'+{abs(ca-cb)}',end='')
		if ca<cb:
			print(f'-{abs(ca-cb)}',end='')
	else:
		print('0',end='')