import sys
cases = int(input())
for i in range(cases):
    stri = input()
    num1 = int(stri.split()[0])
    num2 = int(stri.split()[1])
    if num1 > num2:
        print('>')
    elif num1 < num2:
        print('<')
    elif num1 == num2:
        print('=')