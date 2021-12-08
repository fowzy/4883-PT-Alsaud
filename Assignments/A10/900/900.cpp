#include <iostream>
using namespace std;
int main()
{
    unsigned long long input[5000];
    unsigned long long data;
    input[0] = 0;
    input[1] = 1;
    input[2] = 1;
    while (cin >> data)
    {
        if(data == 1 || data == 2)
            cout << "1" << endl;
        if (data != 0)
        {
            for (int i = 3; i <= data; i++)
            { 
                input[i] = ((input[i-1])+(input[i-2]));
                if(i == data)
                //The Fibonacci number for 5 is 5
                    cout << "The Fibonacci number for " << data << " is " << input[i] << endl;
            }
        }
        else
            break;
    }
    return 0;
}