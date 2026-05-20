def make_int_list(s):
	arr = []
	for i in s.split():
		arr.append(int(i))
	return arr
def is_odd(x):
	if x%2==0:
		return False
	return True
def odd_list(l):
	arr = []
	for i in l:
		if is_odd(i):
			arr.append(i)
	return arr
def sum_square(l):
	result = 0
	for i in l:
		result += i*i
	return result
exec(input().strip())