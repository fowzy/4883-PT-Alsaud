#include <iostream>
using namespace std;
int main()
{
    unsigned long long input[50];
    unsigned long long data;
    input[1] = 1;
    input[2] = 2;
    while (cin >> data)
    {
        if(data == 1)
            cout << "1" << endl;
        if(data == 2)
            cout << "2" << endl;
        if (data != 0)
        {
            for (int i = 3; i <= data; i++)
            { 
                input[i] = ((input[i-1])+(input[i-2]));
                if(i == data)
                    cout << input[i] << endl;
            }
        }
        else
            break;
    }
    return 0;
}