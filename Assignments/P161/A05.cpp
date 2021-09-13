/*
Author      :   Fowzy Alsaud
Online Judge:   P161 - Traffic Lights.
Assignment  :   A05
Date        :   Sept 2nd, 2021
Class       :   Prgm. Tech. with Dr. Griffin.
*/
#include <iostream>

using namespace std;

int main()
{
    // var. data to store a temporary input from the use
    int data, green, timeLine;
    int cycleTime = 0;
    int seconds = 0;
    int orange = 5;
    // store the lights into an array and it should be fixed size accordin to the documation 2 traffic siganls up to 100 signals.
    int traffic_light[100];
    // I use count var. to count how many data that my user has entered
    int count = 0;
    // taking data from the user
    while (1) // using infinite loop and if statement to break if need it
    {
        // taking the data from the user
        cin >> data;
        // if statement check user' data and if it a ZERO then terminate
        if (data != 0)
        {
            // data is not zero then store into the array
            traffic_light[count] = data;
        }
        // means the user has entered a zero so break it
        else
        {
            break;
        }
        // finish the loop and add one :D
        count++;
    }

    // for loop to check and read the element in an array
    for (int i = 0; i < count; i++)
    { // for loop 18000 times which is 18000 seconds == 5 hours
        cycleTime = traffic_light[i];
        green = cycleTime - orange; // 14
        for (int x = 0; x < 18000; x++)
        {
            for (int x = 0; x < 180000; x++)
            {
                if (seconds == green) // 0 == 14
                {
                    cout << seconds << endl;
                }
                seconds++;
            }
            green++;
        }
    }
    return 0;
}