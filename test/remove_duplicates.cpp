#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void removeDuplicates(vector<int> &v)
{

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            v.erase(v.begin() + i);
        }
    }
}
int main()
{
    vector<int> v = {2, 1, 3, 4, 6, 8, 8, 2, 3, 5};
    sort(v.begin(), v.end());
    removeDuplicates(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
}