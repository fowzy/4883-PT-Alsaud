import sys

leng = 0
def fun(n):
    global leng
    leng+=1
    if 0 <  n and n < 1000000:
        if n == 1:
            return 1
        if n%2 ==0:
            return fun(n/2)
        else:
            return fun((n*3)+1)
# while True:
for line in sys.stdin:
    try:
        lengths = []
        i = int(line.split()[0])
        j = int(line.split()[1])
        for x in range(i,j+1):
            leng=0
            fun(x)
            lengths.append(leng)
        print(f'{i} {j} {max(lengths)}')
    except EOFError:
        break
