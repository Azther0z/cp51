a = input().strip()
b = input().strip()
aa = [0]*26
bb = [0]*26
for i in a.lower():
	if 'a'<=i and i<='z':
		aa[ord(i)-ord('a')]+=1
for i in b.lower():
	if 'a'<=i and i<='z':
		bb[ord(i)-ord('a')]+=1
print(a)
check = True
for i in range(26):
	if aa[i]>bb[i]:
		print(f' - remove {aa[i]-bb[i]} {chr(ord("a")+i)}',end='')
		if aa[i]-bb[i]>1:
			print('\'s',end='')
		print()
		check = False
if check: print(f' - None')
print(b)
check = True
for i in range(26):
	if bb[i]>aa[i]:
		print(f' - remove {bb[i]-aa[i]} {chr(ord("a")+i)}',end='')
		if bb[i]-aa[i]>1:
			print('\'s',end='')
		print()
		check = False
if check: print(f' - None')
