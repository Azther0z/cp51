a = input().split(",")
a[0]=a[0][1:]
a[2]=a[2][:-1]
a[0]=float(a[0])
a[1]=float(a[1])
a[2]=float(a[2])
#print(a)
b = input().split(",")
#print(b)
b[0]=b[0][1:]
b[2]=b[2][:-1]
b[0]=float(b[0])
b[1]=float(b[1])
b[2]=float(b[2])
c=[a[0]+b[0],a[1]+b[1],a[2]+b[2]]
print(a,"+",b,"=",c)
'''
b[0]=float(b[0])
b[1]=float(b[1])
b[2]=float(b[2])
print(b)
'''