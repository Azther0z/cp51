def RLE(t): 
	result = []
	if len(t)==0:
		return []
	count=0
	for i in range(len(t)-1):
		count+=1
		if t[i]!=t[i+1]:
			result.append([t[i],count])
			count=0
	if count==0:
		result.append([t[-1],1])
	else:
		result.append([t[-1],count+1])
	return result
exec(input()) 