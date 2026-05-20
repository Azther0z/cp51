n = int(input())
arr = []
while n!=1:
  arr.append(n)
  if n%2==0:
    n = n//2
  else:
    n = 3*n+1
for i in arr[len(arr)-14:]:
  print(f'{i}->',end='')
print(1)