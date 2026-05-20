import numpy as np 
 
def mult_table(n,m): 
   a = np.arange(1,n+1).reshape((n,1))
   b = np.arange(1,m+1)
   return a*b
exec(input().strip())