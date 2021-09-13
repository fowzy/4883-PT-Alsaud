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

using namespace std;
// Function Prototype:
bool isJolly(vector<int>, int);

int main()
{
    int n;             // we storing our input here
    string line;       // string line to read line by line
    vector<int> myVec; // created a vector to store data
    while (getline(cin, line))
    {
            istringstream iss(line);
            myVec.push_back(n);
            isJolly(myVec, myVec.size()) ? cout << "Jolly\n" : cout << "Not Jolly\n";
    }
    return 0;
}
/* Function to check if the line is JOLLY or NOT */
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
