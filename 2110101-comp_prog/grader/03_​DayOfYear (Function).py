def day_of_year(d, m, y): 	
	month = [0,31,0,31,30,31,30,31,31,30,31,30,31]
	y-=543
	if (y%4==0 and y%100!=0) or y%400==0:
		month[2]=29
	else:
		month[2]=28

	b = d
	for i in range(1,m):
		b+=month[i]
	return b
exec(input()) # DON'T remove this line 