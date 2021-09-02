#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream inFile("input");
    int data;
    while(inFile >> data){

    }

    inFile.close();
    return 0;
}