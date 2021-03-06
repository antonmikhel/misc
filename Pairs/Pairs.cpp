// Pairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class PartList
{
public:
    static vector<pair <string, string>> partlist(vector<string> &arr);
};

vector<pair <string, string>> PartList::partlist(vector<string> &arr)
{
    vector<pair<string, string>> v;     
    for (int i = 1; i < arr.size(); i++)
    {        
        string sep = "";
        string strtmp1, strtmp2;
        for (int j = 0; j < i; j++)
        {
            if (j != 0)
                sep = " ";
            strtmp1 += sep + arr[j];
        }          
        sep = "";
        for (int j = i; j < arr.size(); j++)
        {
            if (j != i)
                sep = " ";
            strtmp2 += sep + arr[j];
        }            
        v.push_back(make_pair(strtmp1, strtmp2));
    }    
    return v;
}

bool operator==(const pair<string, string> p1, const pair<string, string> p2)
{
    //return strcmp(p1.first.c_str(), p2.first.c_str()) && strcmp(p1.second.c_str(), p2.second);
    return p1.first == p2.first && p1.second == p2.second;
}

//bool operator==(const vector<pair <string, string>> v1, const vector<pair <string, string>> v2)
//{
//    return (v1.size == v2.size()) && equal(v1.begin(), v1.end(), v2.begin());
//}

template <typename T>
static bool comparevec(vector<T> v1, vector<T> v2)
{
    if (v1.size() != v2.size())
        return false;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return (v1 == v2);
}

void testequal(vector<pair <string, string>> ans, vector<pair <string, string>> sol) 
{
    assert(comparevec(ans, sol));
}

void test()
{
    vector<string> s = { "cdIw", "tzIy", "xDu", "rThG" };
    vector<pair <string, string>> sol = { { "cdIw", "tzIy xDu rThG" },{ "cdIw tzIy", "xDu rThG" },{ "cdIw tzIy xDu", "rThG" } };
    vector<pair <string, string>> ans = PartList::partlist(s);
    testequal(ans, sol);

    s = { "I", "wish", "I", "hadn't", "come" };
    sol = { { "I", "wish I hadn't come" },{ "I wish", "I hadn't come" },{ "I wish I", "hadn't come" },{ "I wish I hadn't", "come" } };
    ans = PartList::partlist(s);
    testequal(ans, sol);

    s = { "vJQ", "anj", "mQDq", "sOZ" };
    sol = { { "vJQ", "anj mQDq sOZ" },{ "vJQ anj", "mQDq sOZ" },{ "vJQ anj mQDq", "sOZ" } };
    ans = PartList::partlist(s);
    testequal(ans, sol);
};


int main()
{
    pair<string, string> p("a", "b");
    vector<pair<string, string>> v;
    cout << p.first << endl;
    cout << p.second << endl;
    v.push_back(p);
    cout << v[0].first << "," << v[0].second << endl;
    test();
    return 0;
}

