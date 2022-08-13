#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getIntegers(string str)
{
    vector<int> v;
    string newStr;
    for (char i : str)
    {
        if (i != ' ')
        {
            newStr += i;
        }
        else
        {

            v.push_back(stoi(newStr));
            newStr = "";
        }
    }
    v.push_back(stoi(newStr));
    return v;
}

int main()
{
    string str;
    vector<int> v;

    getline(cin, str);

    v = getIntegers(str);
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}