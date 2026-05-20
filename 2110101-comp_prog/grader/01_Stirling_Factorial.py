import math

n = int(input())
print(((2*math.pi)**(1/2))*(n**(n+1/2))*(math.e**(-n+(1/(12*n+1)))))
print(((2*math.pi)**(1/2))*(n**(n+1/2))*(math.e**(-n+(1/(12*n)))))