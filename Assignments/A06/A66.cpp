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
    while (getline(cin, line))
    {
        vector<int> myVec;          // created a vector to store data
        istringstream stream(line); // creating an object class of istringstream
        bool jolly = true;
        vector<int> result; // result which is an array can hold 3000 result

        while (stream >> n)
        {
                myVec.push_back(n);
        }

        // for (int i = 0; i < myVec[0]; i++)
        // {
        //     cout <<"";}
        }
        inFile.close();

        return 0;
    }