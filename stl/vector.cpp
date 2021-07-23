#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(4);
    cout << "size of vector: " << num.size() << endl;
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
        ;
    }
    cout << "size of vector: " << num.size() << endl;
    num.insert(num.begin() + 2, 3);
    cout << num.at(2) << endl;
    num.pop_back();
    cout << "size of vector: " << num.size() << endl;
    vector<int>::iterator i;
    for (i = num.begin(); i != num.end(); i++)
    {
        cout << *i << endl;
    }
    cout << "Element in front: " << num.front() << endl;
    cout << "Element at the end: " << num.back() << endl;
    num.erase(num.begin() + 1);
    cout << "size of vector: " << num.size() << endl;
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
        ;
    }
}