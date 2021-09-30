/*
Author      :   Fowzy Alsaud
Online Judge:   P161 - Traffic Lights.
Assignment  :   A05
Date        :   Sept 30th, 2021
Class       :   Prgm. Tech. with Dr. Griffin.
*/
#include <iostream>
#include <vector> // to store the lights
using namespace std;
int main()
{
    int data = 0; // int to save data
    while (1)
    {
        vector<int> lights;              // using vectors to store the data
        while (cin >> data && data != 0) // push data to vector to store the lights time
            lights.push_back(data);
        bool allGreen = false; // to check if all lights are green
        int seconds = 0; // count the seconds
        for (seconds = lights[0]*2; seconds < 18000; seconds++)
        {
            int countTrue = 0; // I put the count true in the loop to make sure that we reset the counter in each seconds 
            for (int i = 0; i < lights.size(); i++)
            {
                if (seconds % (lights[i] * 2) < lights[i] - 5) // I used % to tell if the light is green at that current time &&  lets say the light is 20 seconds and current time is 41 seconds so if 41%40 and not equal to zero and the result between 1 and 15 that means is green
                    countTrue++; 
            }
            if (countTrue == lights.size()) // if the number of green lights equal the number of the lights then It's all green then break and print out the result
            {
                allGreen = true;
                break;
            }
        }
        if (allGreen) // if this statement is true then print out the time
            printf("%02d:%02d:%02d\n", seconds / 3600, seconds % 3600 / 60, seconds % 60);
        if(seconds>=18000) // if the time is more than 5 hours print out this
            cout << "Signals fail to synchronise in 5 hours" << endl;
    }
    return 0;
}