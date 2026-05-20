mp = {}
s = input().strip().lower()
for i in s:
  if not('a'<= i and i<='z'):
    continue
  if i not in mp:
    mp[i] = 0
  mp[i] += 1
ls = []
for i in mp:
  ls.append([-mp[i],i])
ls.sort()
for i in ls:
  print(f"{i[1]} -> {-i[0]}")