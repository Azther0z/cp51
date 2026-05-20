def missing_digits(x):
  arr = ['0','1','2','3','4','5','6','7','8','9']
  for i in x:
    if i in arr:
      arr.remove(i)
  tmp = []
  for i in arr:
    tmp.append(int(i))
  return tmp
s = input()
arr = missing_digits(s)
if len(arr)==0:
  print('None')
else:
  print(arr[0],end='')
  for i in arr[1:]:
    print(f',{i}',end='')