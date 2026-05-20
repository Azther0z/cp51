s = input()
result = ''
res = ''
for i in s.lower():
	if '0'<=i and i<='9':
		res+=i
	if 'a'<=i and i<='z':
		res+=i
	else:
		if len(res)!=0:
			result+=res[0].upper()+res[1:]
		res=''
if len(res)!=0:
	result+=res[0].upper()+res[1:]
res=''
result = result[0].lower()+result[1:]
print(result)