def valid(dna):
	for i in dna:
		if i not in 'ATGCatgc':
			return False
	return True

def R(dna):
	result = ''
	for i in dna:
		if i=='A':
			result += 'T'
		elif i=='T':
			result += 'A'
		elif i=='G':
			result += 'C'
		elif i=='C':
			result += 'G'
	return result[::-1]

def F(dna):
	a=t=g=c=0
	for i in dna:
		if i=='A':
			a+=1
		elif i=='T':
			t+=1
		elif i=='G':
			g+=1
		elif i=='C':
			c+=1
	return a,t,g,c

def D(dna,pair):
	count=0
	for i in range(len(dna)-1):
		if dna[i:i+2]==pair:
			count+=1
	return count	

dna = input().strip().upper()
if not valid(dna):
	print('Invalid DNA')
else:
	op = input().strip()
	if op=='R':
		print(R(dna))
	if op=='F':
		a,t,g,c = F(dna)
		print(f'A={a}, T={t}, G={g}, C={c}')
	if op=='D':
		pair = input().strip().upper()
		print(D(dna,pair))