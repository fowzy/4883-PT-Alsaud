
while True:
    input=[]
    input.append(int(input()))
    input[0] = 0;
    input[1] = 1;
    if (input > 5000):
        break
    if (input == input[0]):
        print('The Fibonacci number for 0 is 0')
    if (input == input[1]):
        print('The Fibonacci number for 1 is 1')
    # else:
    #     for i in range(2,input):
    #         # (int i = 2; i <= data; i++):
    #         input[i] = ((input[i - 2]) + (input[i - 1]));
    #         if (i == n):
    #             print(f'The Fibonacci number for {input} is {input[i]}\n')
