import sys
operations = int(input())
sum = int()
for line in sys.stdin:
    if line.split()[0] == 'donate':
        sum+=int(line.split()[1])
    elif(line.split()[0] == 'report'):
        print(sum)