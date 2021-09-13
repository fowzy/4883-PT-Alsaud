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
    int n;             // we storing our input here
    vector<int> myVec; // created a vector to store data

    string line; // string line to read line by line
    while (getline(inFile, line))
    {
        istringstream stream(line); // creating an object class of istringstream
        while (stream >> n)
        {
            // cout << n << " ";
            myVec.push_back(n);
        }
    }
    
    // isJolly(myVec, myVec.size()) ? cout << "Jolly\n" : cout << "Not Jolly\n";
    // cout << myVec.size() << endl;
    // for(int i: myVec){
    //     cout << i << " ";
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
