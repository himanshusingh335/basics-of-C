#include <iostream>
#include <algorithm>
using namespace std;

int get2largest(int arr[], int arrsize)
{
    int l2 = -1;
    sort(arr, arr + arrsize);
    for (int i = arrsize - 2; i != 0; i--)
    {
        if (arr[i] != arr[arrsize - 1])
        {
            l2 = arr[i];
            break;
        }
    }
    return l2;
}

int main()
{
    int arr[] = {1, 4, 5, 6, 2, 3};
    int arrsize = sizeof(arr) / sizeof(int);
    cout << get2largest(arr, arrsize);
}