#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i];
    cout << " ";
}

void BinaryNum(int n, int i, int arr[])
{
    if (i >= n)
    {
        printArr(arr, n);
        return;
    }
    arr[i] = 0;
    BinaryNum(n, i + 1, arr);
    arr[i] = 1;
    BinaryNum(n, i + 1, arr);
}

int main()
{
    int n;
    cout << "Enter the n : ";
    cin >> n;
    int arr[32];

    BinaryNum(n, 0, arr);
    return 0;
}