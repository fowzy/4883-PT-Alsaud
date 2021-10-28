#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int countZero = 0;
    int data = 0;
start:
    vector<int> lights;
    while (cin >> data)
    {
        if (data != 0)
        {
            lights.push_back(data);
            countZero = 0;
        }
        else if (data == 0)
        {
            // cout << "test";
            countZero++;
            // cout << countZero << endl;
            if (countZero == 3)
                return 0;
            // break;

            else if (countZero == 1)
                goto LOOP;
        }
    }
LOOP:
    bool allGreen = false;
    int seconds = 0;
    for (seconds = (*min_element(lights.begin(), lights.end())) * 2; seconds <= 18000; seconds++)
    {
        int countTrue = 0;
        for (int i = 0; i < lights.size(); i++)
        {
            if (seconds % (lights[i] * 2) < lights[i] - 5)
                countTrue++;
        }
        if (countTrue == lights.size())
        {
            allGreen = true;
            break;
        }
    }
    if (allGreen)
        printf("%02d:%02d:%02d\n", seconds / 3600, seconds % 3600 / 60, seconds % 60);
    else
        cout << "Signals fail to synchronise in 5 hours" << endl;
    goto start;
    return 0;
}