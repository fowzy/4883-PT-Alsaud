#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    int testCase;
    string data;
    getline(cin, data);
    stringstream ss(data);
    ss >> testCase;
    int x = 0;
    for (int r = 0; r <= testCase; r++)
    {
        map<string, int> tree;
        while (getline(cin, data))
        {
            if (data != "")
            {
                tree.insert(make_pair(data, 0));
                x++;
            }
            else
                break;
        }
        for (auto it = tree.begin(); it != tree.end(); it++)
        {
            it->second = (100.00 / tree.size());
        }
        // for (auto it = tree.begin(); it != tree.end(); it++)
        // {
        //     if (it->first == it->first & it->second <= it->second)
        //     {
        //         it->second += it->second;
        //     }
        // }
        for (auto it = tree.begin(); it != tree.end(); it++)
            cout << it->first << " " << fixed << setprecision(4) << it->second << endl;
    }
    return 0;
}
