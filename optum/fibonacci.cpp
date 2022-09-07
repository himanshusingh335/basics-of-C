#include <iostream>

using namespace std;

int main()
{
    int n, t1 = 0, t2 = 1, nextnum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << t1 << " ";
        }
        else if (i == 2)
        {
            cout << t2 << " ";
        }
        nextnum = t1 + t2;
        t1 = t2;
        t2 = nextnum;
        cout << nextnum << " ";
    }
    return 0;
}