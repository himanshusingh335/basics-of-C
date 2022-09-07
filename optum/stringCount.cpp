#include <iostream>
#include <string>
using namespace std;

int countIn(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (s[i + 1] == 'i')
            {
                if (s[i + 2] == 'n')
                {
                    if (s[i + 3] == ' ')
                    {
                        count += 1;
                        i += 3;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    string s;
    getline(cin, s);
    cout << countIn(s);
}