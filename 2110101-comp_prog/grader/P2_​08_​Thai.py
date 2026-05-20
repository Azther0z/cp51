def to_Thai(n):
	result=""
	table=['soon','neung','song','sam','si','ha','hok','chet','paet','kao','sip']
	if n==0:
		return 'soon'
	if n==1:
		return 'neung'
	if n>=1000:
		result+=table[n//1000]+' '
		result+='pun '
		n%=1000
	if n>=100:
		result+=table[n//100]+' '
		result+='roi '
		n%=100
	if n>=30:
		result+=table[n//10]+' sip '
		n%=10
	elif n>=20:
		result+='yi sip '
		n%=10
	elif n>=10:
		result+='sip '
		n%=10
	if n>=1:
		if n==1:
			result+='et '
		else:
			result+=table[n]
	return result.strip()
exec(input().strip())