def check_digit(n): 
	x=0
	for i in range(12):
		x+=(13-i)*int(n[i])
	return (11-(x%11))%10
exec(input()) # DON'T remove this line 