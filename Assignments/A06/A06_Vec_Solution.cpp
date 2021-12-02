/*
Author      :   Fowzy Alsaud
Online Judge:   P161 - Traffic Lights.
Assignment  :   A06
Date        :   Sept 13th, 2021
Class       :   Prgm. Tech. with Dr. Griffin.
*/
#include <iostream>
#include <vector>  // for vector
#include <sstream> // for istringstream
#include <cmath>   // for abs
#include <fstream>

using namespace std;
int main()
{
    string line; // string line to read line by line
    fstream inFile("input");
    while (getline(inFile, line))
    {
        vector<int> myVec;          // created a vector to store data
        istringstream stream(line); // creating an object class of istringstream to conver our string "line" into an int
        vector<int> result;         // result which is a vector can hold the differences between an element and other
        int x;                      // var to store the data into an integer
        bool isJolly = true;
        // WHILE LOOP TO PUSH DATA INTO THE ARRAY
        while (stream >> x)
        {
            myVec.push_back(x);
        }
        // n is the size of the vector
        // FOR LOOP WILL LOOP N TIMES WHICH IS GOING TO BE OUR FIRST ELEMENT IN MY ARRAY = ARRAY[0]
        int n = myVec[0];
        if (n == 1)
        {
            cout << "Jolly\n";
        }
        else
        {
            // vector<int> present;
            int present[n];
            // push back the result
            for (int j = 1; j < n; j++)
            {
                result.push_back(abs(myVec[j + 1] - myVec[j]));
            }
            for (int i = 0; i < result.size(); i++)
            {
                //
                int curr_result = result[i];
                if (present[curr_result] == 0)
                {
                    present[curr_result] = 1;
                }
            }
            for (int i = 1; i < sizeof(present)/sizeof(present[0]); i++)
            {
                //
                if (present[i] == 0)
                {
                    isJolly = false;
                    break;
                }
            }
            if (!isJolly) // IS NOT TRUE
            {
                cout << "Not jolly\n";
            }
            if (isJolly) // IS TRUE
            {
                cout << "Jolly\n";
            }
        }
    }
    inFile.close();
    return 0;
}