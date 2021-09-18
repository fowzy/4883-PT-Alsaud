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
    int n;       // we storing our input here
    string line; // string line to read line by line
    fstream inFile("input");
    while (getline(inFile, line))
    {
        vector<int> myVec;          // created a vector to store data
        istringstream stream(line); // creating an object class of istringstream
        bool jolly = true;
        vector<int> result; // result which is an array can hold 3000 result

        while (stream >> n)
        {
            myVec.push_back(n);
        }

        for (int i = 1; i < myVec.size(); ++i) // reading and start comparing between items.
        {
            result.push_back(abs(myVec[i] - myVec[i - 1]));
        }

        // if the size of the vector is 1 means it has only two elements that means there is nothing to check
        if (result.size() == 1)
        {
            cout << "Jolly\n";
        }
        else
        {
            for (int i = 1; i < result.size(); i++)
            {
                if (result[i] > result[i - 1])
                {
                    jolly = false;
                }

                if (!jolly) // If notJolly == false so it's Not Jolly
                {
                    cout << "Not Jolly\n";
                    break;
                }
            }

            if (jolly) // if NOT false then is TRUE means is JOLLY
            {
                cout << "Jolly\n";
            }
        }
    }

    return 0;
}