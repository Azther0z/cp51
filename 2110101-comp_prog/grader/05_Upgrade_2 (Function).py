def index_of(grades, ID):
  for i in range(len(grades)):
    if grades[i][0]==ID:
      return i
  return -1

def upgrade(grades, IDs):
  g = ['F','D','D+','C','C+','B','B+','A']
  for i in range(len(grades)):
    if grades[i][0] in IDs:
      idx = g.index(grades[i][1])
      grades[i][1] = g[min(len(g)-1,idx+1)]
  grades.sort()
# DON'T remove the following three lines
exec(input())
exec(input()) 
exec(input())
