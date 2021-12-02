#include <iostream>
using namespace std;

int main()
{
    uint input[5001];
    uint data;
    input[0] = 0;
    input[1] = 1;
    while (cin >> data)
    {
        if (data > 5000)
            break;
        if (data == 0)
            cout << "The Fibonacci number for 0 is 0" << endl;
        if (data == 1)
            cout << "The Fibonacci number for 1 is 1" << endl;
        else
        {
            for (int i = 2; i <= data; i++)
            {
                input[i] = ((input[i - 2]) + (input[i - 1]));
                if (i == data)
                    cout << "The Fibonacci number for " << data << " is " << input[i] << endl;
            }
        }
    }
    return 0;
}