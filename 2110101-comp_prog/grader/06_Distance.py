def distance1(x,y,xx,yy):
	return ((x-xx)**2+(y-yy)**2)**0.5
def distance2(p,pp):
	return distance1(p[0],p[1],pp[0],pp[1])
def distance3(c,cc):
	return distance1(c[0],c[1],cc[0],cc[1]),c[2]+cc[2]>=distance1(c[0],c[1],cc[0],cc[1])
def perimeter(arr):
	arr.append(arr[0])
	result = 0
	for i in range(len(arr)-1):
		result += distance2(arr[i],arr[i+1])
	return result
exec(input())