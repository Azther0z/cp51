arr = input().strip().split()
arr[0]=float(arr[0])
arr[1]=float(arr[1])
arr[2]=float(arr[2])
arr[3]=float(arr[3])
SUM = arr[0]+arr[1]+arr[2]+arr[3]
mx = 0
mn = 1e9
def findMin(a,b):
  if a<b:
    return a
  return b
def findMax(a,b):
  if a>b:
    return a
  return b
mx = findMax(mx,arr[0])
mx = findMax(mx,arr[1])
mx = findMax(mx,arr[2])
mx = findMax(mx,arr[3])
mn = findMin(mn,arr[0])
mn = findMin(mn,arr[1])
mn = findMin(mn,arr[2])
mn = findMin(mn,arr[3])
print(round((SUM-mn-mx)/2,2))