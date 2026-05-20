def total(pocket): 
	result = 0
	for i in pocket:
		result += i*pocket[i]
	return result
def take(pocket, money_in): 
    for i in money_in:
    	if i not in pocket:
    		pocket[i] = 0
    	pocket[i] += money_in[i] 
def pay(pocket, amt): 
	paid = {}
	for i in pocket:
		if amt//i<=0:
			continue
		paid[i] = min(amt//i,pocket[i])
		amt -= i*paid[i]
	if amt>0:
		return {}
	else:
		for i in pocket:
			if i in paid:
				pocket[i] -= paid[i]
		return paid
exec(input().strip())