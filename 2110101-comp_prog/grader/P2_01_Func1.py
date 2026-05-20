def is_odd(n):
	if n%2==0: return False
	return True
def has_odds(x):
	for i in x:
		if is_odd(i): return True
	return False
def all_odds(x):
	for i in x:
		if not is_odd(i): return False
	return True
def no_odds(x):
	if has_odds(x): return False
	return True
def get_odds(x):
	arr = []
	for i in x:
		if is_odd(i): arr.append(i)
	return arr
def zip_odds(a, b):
	aa = get_odds(a)
	bb = get_odds(b)
	n = min(len(aa),len(bb))
	arr = []
	for i in range(n):
		arr.append(aa[i])
		arr.append(bb[i])
	for i in aa[n:]:
		arr.append(i)
	for i in bb[n:]:
		arr.append(i)
	return arr
exec(input().strip())