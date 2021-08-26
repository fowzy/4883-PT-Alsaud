/**
* Fowzy Alsaud
* PT 4883 - Dr. Griffin
* August 26th, 2021
*/
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    int B = 0, A = 0;
    while (cin >> A >> B) {
        // diff is a variable to count the difference of number of soldiers between Hashmat’s army and his opponent’s army
        int diff= B-A;
        // print out the result 
        cout << diff << endl;
    }
    return 0;
}