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
#include <fstream> // reading inFile

using namespace std;
// Function Prototype:
bool isJolly(vector<int>, int);

int main()
{
    fstream inFile("input");
    int n[3000];       // we storing our input here
    vector<int> myVec; // created a vector to store data
    int count=0;
    for (int i = 0; i <= 3000; i++)
    {
        while (inFile.good())
        {
            string line; // string line to read line by line
            while (getline(inFile, line))
            {
                istringstream stream(line); // creating an object class of istringstream
                stream >> n[i];
                while (stream >> n[i])
                {
                    cout << n << " ";
                    myVec.push_back(n[i]);
                }
                // isJolly(myVec, myVec.size()) ? cout << "Jolly\n" : cout << "Not Jolly\n";

                cout << endl;
            }
            count++;
            // cout << myVec.size() << " ";
        }
    }
    // for (int i: myVec){
    //         cout << i << " ";
    // }
    // int result[3001]; // result which is an array can hold 3000 result
    // int length = 1;
    // for (int i = 1; i < myVec.size(); ++i) // reading and start comparing between items.
    // {
    //     result[i] = myVec[i] - myVec[i - 1];
    //     length++;
    //     cout << abs(result[i]) << endl;
    // }
    inFile.close();
    return 0;
}

bool isJolly(vector<int> v, int n)
{

    vector<bool> diffSet(n, false);

    // Traverse arrays
    for (int i = 0; i < n - 1; i++)
    {
        // Find absolute difference between current two
        int d = abs(v[i] - v[i + 1]);

        // If difference is out of range or repeated,
        // return false.
        if (d == 0 || d > n - 1 || diffSet[d] == true)
            return false;

        // Set presence of d in set.
        diffSet[d] = true;
    }

    return true;
}
