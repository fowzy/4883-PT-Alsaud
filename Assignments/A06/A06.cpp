#include <iostream>
#include <vector>  // for vector
#include <sstream> // for istringstream
#include <cmath>   // for abs
#include <ifstream> // reading inFile

using namespace std;
// Function Prototype:
bool isJolly(vector <int> , int);

int main()
{
    int n;              // we storing our input here
    string line;        // string line to read line by line
    vector<int> myVec;  // created a vector to store data
    getline(cin, line); // get input from the user and store it into the line
    std::istringstream iss(line);
    while (iss >> n) // while loop to read and push the data to our vector
    {
        myVec.push_back(n);
    }

    isJolly(myVec, myVec.size()) ? cout << "Jolly\n" : cout << "Not Jolly\n";

    // int result[3001]; // result which is an array can hold 3000 result
    // int length = 1;
    // for (int i = 1; i < myVec.size(); ++i) // reading and start comparing between items.
    // {
    //     result[i] = myVec[i] - myVec[i - 1];
    //     length++;
    //     cout << abs(result[i]) << endl;
    // }
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
