def print_triangle(h): 
    result = []
    result.append('*'*(h+h-1))
    for i in range(1,h):
        tmp = ''
        tmp += '.'*i
        tmp += '*'
        tmp += '.'*(2*(h-i-1)-1)
        if i!=h-1:
            tmp += '*'
        result.append(tmp)
    for i in result[::-1]:
        print(i)
exec(input()) # DON'T remove this line 