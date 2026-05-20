s = input()
t = ''
for i in range(len(s)):
	if s[i]=='(':
		t += ('[')
	elif s[i]==')':
		t += (']')
	elif s[i]=='[':
		t += ('(')
	elif s[i]==']':
		t += (')')
	else:
		t += (s[i])
print(t)