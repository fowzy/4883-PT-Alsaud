/*
Author  :   Fowzy Alsaud
Date    :   Oct 18th 2021
UVA     :   10226 ('https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167')
uDebug  :   https://www.udebug.com/UVa/10226
Description : Find the percentage of the spieces that are provided to us
*/
#include <bits/stdc++.h> // for sort
#include <iostream>
#include <vector>  // for vector
#include <string>  // for string
#include <sstream> // for stringstream
#include <iomanip> // to fixed and setprecision

using namespace std;

struct tree
{                      // making my own data type
    string treeName;   // to store tree name
    double percentage; // to store the percentage
};

int main()
{
    // no species name exceeds 30 characexecutters
    // no more than 10,000 species
    // no more than 1,000,000 trees
    int testCase; // store the number of cases
    string data;  // data is string to store the data temporary
    // get the number of the cases
    getline(cin, data);    // get the first line
    stringstream ss(data); // use string stream for converting
    ss >> testCase;        // convert the string to int using stringstream

    for (int r = 0; r <= testCase; r++)
    {
        vector<tree> trees; // store trees names

        // start getting the trees
        while (getline(cin, data))
        {                                   // pushing my trees to my vector "trees"
            if (data != "")                 // remove spaces
                trees.push_back({data, 0}); // then push to the vector
            else
                break;
        }
        cout << r << endl; // followed by a blank which will be in between consecutive cases
        // sorting by alphabetical order using sort
        sort(trees.begin(), trees.end(), [](tree a, tree b)
             { return a.treeName < b.treeName; });
        // run a for loop to show up the percentage of the hardwood species
        for (int i = 0; i < trees.size(); i++)
            trees[i].percentage = 100.00 / trees.size();
        // // for loop to complete calculating the percentage of the duplication
        for (int i = 0; i < trees.size(); i++)
        {
            int percentI = trees[i].percentage;
            for (int j = i + 1; j < trees.size(); j++)
            {
                if (trees[i].treeName == trees[j].treeName)
                    trees[i].percentage += trees[j].percentage;
            }
            for (int x = i + 1; x < trees.size(); x++)
            {
                int percentX = trees[x].percentage;
                if (trees[i].treeName == trees[x].treeName & percentI <= percentX)
                {
                    trees.erase(trees.begin() + x);
                    x--; // I have to go back one element because the size of the vector changed cause of the removing
                }
            }
        }
        // finally a loop to print out the result
        for (int i = 0; i < trees.size(); i++)
            cout << trees[i].treeName << " " << fixed << setprecision(4) << trees[i].percentage << endl;
    }
    return 0;
}