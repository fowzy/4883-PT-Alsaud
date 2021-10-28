#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct tree
{
    string treeName;
    double percentage;
};

int main()
{
    int testCase;
    string data;
    getline(cin, data);
    stringstream ss(data);
    ss >> testCase;
    for (int r = 0; r <= testCase; r++)
    {
        vector<tree> trees;
        while (getline(cin, data))
        {
            if (data != "")
                trees.push_back({data, 0});
            else
                break;
        }
        sort(trees.begin(), trees.end(), [](tree a, tree b)
             { return a.treeName < b.treeName; });
        for (int i = 0; i < trees.size(); i++)
            trees[i].percentage = 100.00 / trees.size();
        for (int i = 0; i < trees.size(); i++)
        {
            int percentI = trees[i].percentage;
            for (int j = i + 1; j < trees.size(); j++)
            {
                int percentX = trees[j].percentage;
                if (trees[i].treeName == trees[j].treeName & percentI <= percentX)
                {
                    trees[i].percentage += trees[j].percentage;
                    trees.erase(trees.begin() + j);
                    j--;
                }
            }
            cout << trees[i].treeName << " " << fixed << setprecision(4) << trees[i].percentage << endl;
        }
        if(!trees.empty()){
            trees.clear();
        }
        cout << endl;
    }
    return 0;
}