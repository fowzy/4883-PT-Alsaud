import sys
x=1
for line in sys.stdin:
    if line == 'Hajj':
        print(f'Case {x}: Hajj-e-Akbar')
    elif line == 'Umrah':
        print(f'Case {x}: Hajj-e-Asghar')
    elif line == '*':
        breakpoint
    x+=1