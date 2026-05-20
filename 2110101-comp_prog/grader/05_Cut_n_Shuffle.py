def cut(card):
	first = card[:len(card)//2]
	second = card[len(card)//2:]
	return second+first

def shuffle(card):
	first = card[:len(card)//2]
	second = card[len(card)//2:]
	result = []
	for i in range(len(card)//2):
		result.append(first[i])
		result.append(second[i])
	return result

card = input().split()
q = input().strip()
for x in q:
	if x=='C':
		card = cut(card)
	if x=='S':
		card = shuffle(card)
for x in card:
	print(x,end=' ')