#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int len = 0;
int fun(int n)
{
    len += 1;
    if (0 < n < 1000000)
    {
        if (n == 1)
            return 1;
        if (n % 2 == 0)
            return fun(n / 2);
        else
            return fun((n * 3) + 1);
    }
}

int main()
{
    string data;
    while (getline(cin, data))
    {
        int i, j, x, y;
        stringstream ss(data);
         // i >> j
         // i/x should be smaller
         // j/y should be the bigger one
        ss >> x >> y;
        if (x > y)
        {
            j = x;
            i = y;
        }
        else
        {
            i = x;
            j = y;
        }
        // int length[j] = {};
        vector<int> length;
        for (int r = i; r <= j; r++)
        {
            len = 0;
            fun(r);
            length.push_back(len);
        }
        int max = length[0];
        for (int e = 0; e < length.size(); e++)
        {
            if (length[e] > max)
                max = length[e];
        }
        cout << x << " " << y << " " << max << endl;
        length.clear();
    }
    return 0;
}