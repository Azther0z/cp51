def check_digit(n): 
	x=0
	for i in range(12):
		x+=(13-i)*int(n[i])
	return (11-(x%11))%10

n = input()
print(n[0],n[1:5],n[5:10],n[10:],check_digit(n))