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
#include <algorithm>
#include <set>

using namespace std;
int main()
{
    string line; // string line to read line by line
    fstream inFile("input2");
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
        // for (int i = 0; i < n; i++) // reading and start comparing between items.
        // {
        if (n == 1)
        {
            cout << "Jolly\n";
        }
        else
        {
            // MY VECTOR [4 1 2 3 6]
            //          1   2   3   4
            //      ------------------
            //         [1,  2,  3,  6]
            //  HOW DOES MY FOR LOOP WORKS!
            // n = Vector[0]= 4
            // myVec[2] - myVec[1] >> 1 - 1 = 3
            // myVec[3] - myVec[2] >> 1 - 4 = 1
            // myVec[6] - myVec[3] >> 3 - 3 = 2
            // >> then push it to the result vector
            for (int j = 1; j < n; j++)
            {
                result.push_back(abs(myVec[j + 1] - myVec[j]));
            }
            // cout << "size of n is: " << n << endl;
            // for(int x=0;x<result.size();x++){
            //     cout << result[x] << " ";
            // }
            // cout << "\n";
            for (int i = 1; i <= n - 1; i++)
            {
                // if (!binary_search(result.begin(), result.end(), i))
                // 1-n-1
        // if 1 > 1 && 1 > 3 >> FALSE
        // if 1 > 1 && 1 > 3 >> FALSE
        // if 3 > 1 && 3 > 3 >> TRUE
                if (result[i] < 1 && result[i] > n - 1)
                {
                    isJolly = false;
                    // cout << "Jolly\n";
                }
                else
                {
                    // cout << "Not jolly\n";
                    isJolly = true;
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

        // HOW DOES MY IF STATEMENT WORKS
        // RESULT VECTOR [0    1   2   3]
        //-------------------------
        //               [1,   4,  3,  5]
        // n = 4

        // if (result[i] >= 1 && result[i] <= n - 1)
        // result [0] = 3 >=1 & 3<=3 TRUE
        // result [1] = 1 >=1 & 1<=3 TRUE
        // result [2] = 2 >=1 & 2<=3 TRUE
        // if (3>1 && 3 < 4)
        // true
        // if (1>1 && 3<1)
        // false
        // if (1>1 && 3<1)
        // false
        // if (5>1 && 3<5)
        // true

        // if  (result[i] == 0 || result[i] > n-1)
        // result [0] = 3 == 0 || 3>3 TRUE
        // result [1] = 1 == 0 || 1>3 TRUE
        // result [2] = 2 == 0 || 2>3 TRUE

        // n = 5
        // n =4
        // [4 1 2 3 6]
        // 1-4 = 3
        // 2-1 = 1
        // 3-2 = 1
        // 6-1 = 5
        // so result will be like this
        // result[0] = 3
        // result[1] = 1
        // result[2] = 1
        // result[3] = 5

        // if 1 > 3 && 1 > 1 >> FALSE
        // if 1 > 3 && 1 > 2 >> FALSE
        // if 3 > 3 && 3 > 3 >> TRUE

        /*
        4 1 4 2 3       Jolly
        51 4 2 -1 6     Not jolly
        11 7 4 2 1 6    Jolly
        */
    }
    inFile.close();
    return 0;
}