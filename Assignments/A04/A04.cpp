/**
* Fowzy Alsaud
* PT 4883 - Dr. Griffin
* August 26th, 2021
*/
#include <iostream>
#include <fstream>
#include <cmath> // for abs method

#define endl "\n"

using namespace std;

int main()
{
    fstream inFile("input");
    int B = 0, A = 0;
    while (inFile >> A >> B)
    {
        // diff is a variable to count the difference of number of soldiers between Hashmat’s army and his opponent’s army
        // Method #1 : using abs()
        long long diff = B - A;
        long long C = B - A;
        // print out the result
        // cout << abs(diff) << endl;
        cout << abs(diff) << endl;
        //
        //
        // Method #2 : using if statement
        // if (A >= B){
        //     C = A - B;
        // 	cout << C << endl;
        // }
        // else{
        //     C = B - A;
        // 	cout << C << endl;
        // }
    }
    inFile.close();
    return 0;
}