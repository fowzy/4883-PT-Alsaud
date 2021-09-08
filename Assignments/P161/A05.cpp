/*
Author      :   Fowzy Alsaud
Online Judge:   P161 - Traffic Lights.
Assignment  :   A05
Date        :   Sept 2nd, 2021
Class       :   Prgm. Tech. with Dr. Griffin.
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    fstream inFile("input");
    // data repersent the cycle time of the traffic lights.
    // char data[100];
    int data;
    int size = 0;
    // Each input/number represents the cycle time of a single sign.
    double cycle_time;

    // input will be spread over many lines.
    while (inFile >> data)
    {
        // each number of the input represent the cycle time that traffic may move in one direction
        cycle_time = data - 5;
        // green - 5 (because the last 5 seconds of green cycle is accually orange)
        cout << cycle_time << endl;
        // cycle time will not be less than 10 seconds, nor more than 90 seconds
        // if (!cycle_time < 10 && cycle_time >= 90){

        // }
        // else {
        //     cycle_time =
        // }
        // line no longer than 100 characters.
        // size = strlen(data);
        // if (size >= 100)
        // {
        //     cout << "max is 100 char per line." << endl;
        // }
        // else
        // {
        //     cout << data << endl;
        // }
        
        // Output is the time that it takes for all signals to show shwo green after at least one of them changes to orange. 
        cout << cycle_time << endl;
    }
    inFile.close();
    return 0;
}