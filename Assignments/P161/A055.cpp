#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int countZero = 0;
    while (true)
    {
        int data = 0;
        vector<int> lights;
        while (cin >> data)
        {
            if (data != 0){
                lights.push_back(data);
                countZero=0;
            }
            else
            {
                if (data == 0)
                {
                    countZero++;
                    break;
                }
            }
        }
        if (countZero == 3)
            break;
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
    }
    return 0;
}