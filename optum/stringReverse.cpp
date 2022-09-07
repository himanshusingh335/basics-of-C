#include <iostream>
#include <algorithm>

using namespace std;

void reverseString(string &s, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(s[l], s[r]);
    reverseString(s, l + 1, r - 1);
}

int main()
{
    string s = "Hello";
    reverseString(s, 0, s.size() - 1);
    cout << s;
    return 0;
}