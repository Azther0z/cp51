key = input()
s = input()
s = s.replace('(',' ')
s = s.replace(')',' ')
s = s.replace('"',' ')
s = s.replace("'",' ')
s = s.replace(',',' ')
s = s.replace('.',' ')
s = s.split()
count=0
for i in s:
	if i==key:
		count+=1
print(count)