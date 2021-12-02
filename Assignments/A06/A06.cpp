/*
Author      :   Fowzy Alsaud
Online Judge:   10038 - Jolly Jumpers.
Assignment  :   A06
Date        :   Sept 13th, 2021
Class       :   Prgm. Tech. with Dr. Griffin.
*/
#include <iostream>
#include <set>     // use set
#include <sstream> // for istringstream
#include <cmath>   // for abs
#include <fstream> // in case user want to read input file
using namespace std;
int main()
{
    string line;             // string line to read line by line
    fstream inFile("input"); // reading an input file
    // in case user want to read a file please switch the line below"cin" to "inFile"
    while (getline(cin, line)) // while loop and start reading line by line
    {
        int intArray[3000];         // created a vector to store data
        istringstream stream(line); // creating an object class of istringstream to conver our string "line" into an int
        int r = 0;                  // r to get count how many items is exactly in the array and make it easier to read
        // WHILE LOOP TO PUSH DATA INTO THE ARRAY
        int x; // var to store the data into an integer
        while (stream >> x)
        {
            intArray[r] = x; // store the element into the array
            r++;             // start counting how many elements
        }
        int n = intArray[0]; // this is n which is how many item in each line
        if (n == 1)          // if n == 1 means is Jolly and we don't have to do anything
            cout << "Jolly\n";
        else
        {
            set<int> setOfDifferent; // creating a set to store the different between each number and number
            for (int j = 1; j < n; j++)
                setOfDifferent.insert(abs(intArray[j + 1] - intArray[j])); // calculating the different and getting the absolute value.
            bool isJolly;                                                  // creating a boolean to  see if the line is Jolly or not
            for (int u = 1; u <= n - 1; u++)
            {                                                       // this loop will help me read into the set and see if the following elements exist in the set which 1 through n-1
                if (setOfDifferent.find(u) != setOfDifferent.end()) // using find to find u if yes continue
                {
                    // switch isJolly to true
                    isJolly = true;
                    continue; // then continue till you find the last element
                }
                else
                {
                    // if the element is not there switch back the boolean to false to prevent printing the wrong data
                    isJolly = false;
                    cout << "Not jolly\n"; // print Not Jolly then break it
                    break;
                }
            }
            if (isJolly == true) // if the loop ends and didn't break and the boolean still true then print out Is Jolly.
                cout << "Jolly\n";
        }
    }
    inFile.close(); // close the file
    return 0;
}