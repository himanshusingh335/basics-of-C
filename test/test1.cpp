#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {2, 1, 3};
    int arr[] = {1, 2, 3};
    vector<string> h1;
    string l;
    string h = "hello my name is Himanshu";
    string::iterator it;
    a.insert(a.begin() + 2, 4);
    int *min = min_element(begin(arr), end(arr));
    cout << *min << endl;
    // sort(a.begin(), a.end());
    sort(begin(arr), end(arr));
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    for (it = h.begin(); it != h.end(); it++)
    {
        if (*it != ' ')
        {
            l.push_back(*it);
        }
        else
        {
            h1.push_back(l);
            l = "";
        }
    }
    for (auto i : h1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < h.length(); i++)
    {
        if (h[i] == ' ')
        {
            cout << "bb";
        }
    }
}
