#include <iostream>
using namespace std;
int main(){
    string str;
    int caseNumber=1;
    while(cin >>str){
        if(str =="Hajj")
            cout << "Case " << caseNumber << ": Hajj-e-Akbar" << endl;
        else if(str == "Umrah")
            cout << "Case " << caseNumber << ": Hajj-e-Asghar" << endl;
        else if(str =="*")
            break;
        caseNumber++;
    }
    return 0;
}