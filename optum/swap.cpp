#include <iostream>

using namespace std;

void mySwap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 2;
    int b = 3;
    int *aa = &a;
    int *bb = &b;
    cout << a << " " << b << endl;
    mySwap(*aa, *bb);
    cout << a << " " << b << endl;
}