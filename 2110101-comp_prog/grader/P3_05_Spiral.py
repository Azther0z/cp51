def spiral_square(n):
    arr=[]
    for i in range(n):
        tmp=[]
        for j in range(n):
            tmp.append(0)
        arr.append(tmp)
    i=n//2
    j=n//2
    di=[0,-1,0,1]
    dj=[1,0,-1,0]
    k=0
    current=1
    step=1
    while current<=n*n:
        tmp=step
        while tmp>0:
            arr[i][j]=current
            i+=di[k]
            j+=dj[k]
            current+=1
            tmp-=1
        k=(k+1)%4
        if k%2==0:
            step+=1
    return arr
def print_square(s): 
    for i in range(len(s)): 
        print(' '.join([(2*' '+str(e))[-3:] for e in s[i]])) 
exec(input().strip())