#include <iostream>
#include <sstream> // stringstream
#include <vector>  // vectors
#include <iomanip>
using namespace std;

// convert int to char
string int2hieroglyphs(int n)
{              // 4023 as an example I should take the 4000 which is 8888, then 20 which is nn, and then 3 which is |||
    string ss; // store the result into hieroglyphs
    int reminder = n;
    // for ten-thousand
    int timesTT = reminder / 10000; // count the number of symbol
    reminder = reminder % 10000;    // calculate the reminder

    // for thousand
    int timesT = reminder / 1000;
    reminder = reminder % 1000;

    // for hundred
    int timesH = reminder / 100;
    reminder = reminder % 100;

    // for ten
    int timesTEN = reminder / 10;
    reminder = reminder % 10;

    // for one
    int timesONE = reminder / 1;
    reminder = reminder % 1;

    // printing in order |, n, 9, 8, then r
    for (int i = 0; i < timesONE; i++)
        ss.append("|");
    if (timesONE != 0)
        ss.append(" ");
    for (int i = 0; i < timesTEN; i++)
        ss.append("n");
    if (timesTEN != 0)
        ss.append(" ");
    for (int i = 0; i < timesH; i++)
        ss.append("9");
    if (timesH != 0)
        ss.append(" ");
    for (int i = 0; i < timesT; i++)
        ss.append("8");
    if (timesT != 0)
        ss.append(" ");
    for (int i = 0; i < timesTT; i++)
        ss.append("r");
    if (timesTT != 0)
        ss.append(" ");
    return ss;
}
// convert hieroglyphs(string) to an integer
int string2int(string input)
{
    int n = 0; // what is the number
    // using stringstrimg to remove spaces
    stringstream ss(input);
    string cc;
    // break the string into characters
    while (ss >> cc)
    {
        for (auto x : cc)
        {
            if (x == '|') // for one
                n++;
            else if (x == 'n') // for ten
                n += 10;
            else if (x == '9') // for hundred
                n += 100;
            else if (x == '8') // for thousand
                n += 1000;
            else if (x == 'r') // for ten-thousand
                n += 10000;
        }
    }
    return n;
}
void doEverthing(int l, int r)
{
    // testing
    cout << l << " x " << r << endl;
    // n as an example is 5 so we to start from 1 then double the number till we get number equal or less than n(ex: 5) so we're getting 1,2,4
    vector<pair<int, int>> vect; // Copy right to Byron for mentioning vector pairs for me. THANK :) which will store the left and right side
    // creating a vector to store the left side invdi.
    vector<int> leftSide;
    int curr_value = 1;
    while (curr_value <= l)
    {
        leftSide.push_back(curr_value);
        // the left side start from 1 and keep doubling
        curr_value = (curr_value * 2);
    }
    // creating a vector to store the right side indiv.
    vector<int> rightSide;
    for (int i = 0; i < leftSide.size(); i++)
    {
        if (leftSide.size() == 0)
        {
            return;
        }
        rightSide.push_back(r);
        // the right side in each loop have to be doubled
        r = r * 2;
    }

    // pushing left and right side into the vector pairs
    for (int i = 0; i < rightSide.size(); i++)
        vect.push_back(make_pair(leftSide[i], rightSide[i]));
    int total = 0;     // to calculate the result
    int reminader = l; // reminder is whatever left from the left
    vector<int> starLocation; // to see where is the star location

    // NOW WE HAVE TO COMPARE PAIRS[FIRST ELEMENT] AND SEE IF THE FIRST ELEMENT IS BIGGER THAN THE LEFT SIDE IF NOT THEN ADD THEM TO MY TOTAL
    for (int i = vect.size() - 1; i >= 0; i--)
    {
        // if the left side less or = to reminder then go in
        if (vect[i].first <= reminader)
        {
            // store the location to print the star
            starLocation.push_back(i);
            // get the reminder value which is (=to left side) and subtract the left side
            reminader -= vect[i].first;
            // then get the right side and add it to total to get the calculation
            total += vect[i].second;
        }
    }
    // testing
    // for (int i = 0; i < leftSide.size(); i++)
    // {
    //     cout << leftSide[i] << " ";
    //     for (int j = 0; j < starLocation.size(); j++)
    //     {
    //         if (starLocation[j] == i)
    //             cout << "*  ";
    //     }
    //     cout << "   " << rightSide[i] << endl;
    // }
    // cout << "The solution is: " << total << endl;

    // for loop to prit out the result one by one
    for (int i = 0; i < vect.size(); i++)
    {
        cout << int2hieroglyphs(vect[i].first);
        for (int j = 0; j < starLocation.size(); j++)
        {
            if (starLocation[j] == i)
                cout << "*";
        }
        cout  << int2hieroglyphs(vect[i].second) << endl;
        // cout << " Critic " << setw(6) << " Audience " << setw(0) << " Title " << endl;
    }
    cout << "The solution is: " << int2hieroglyphs(total) << endl;
}

int main()
{
    vector<string> inpts;
    string input;
    while (cin)
    {
        getline(cin, input);
        if (input.empty())
            break;
        inpts.push_back(input);
    }

    // testing
    // doEverthing(5, 3);
    // cout << int2hieroglyphs(5);
    // doEverthing(27, 483);
    // doEverthing(2, 2);
    // cout << string2int("|||||| nnn 99999 88888 rrrrrr") << endl << endl;
    // doEverthing(10, 10000);
    // doEverthing(90000, 11111);
    // cout << int2hieroglyphs(999990000);
    // doEverthing(90000, 90000);
    // doEverthing(99999, 99999);

    for (int i = 1; i < inpts.size(); i += 2)
    {
        int leftSide = string2int(inpts[i]);
        int rightSide = string2int(inpts[i - 1]);
        doEverthing(leftSide, rightSide);
    }

    return 0;
}