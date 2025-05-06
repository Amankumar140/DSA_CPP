#include <iostream>
using namespace std;
int linearsearch(int arr[], int sz, int x)
{
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 5, 9, 23, 90};
    int sz = sizeof(arr);
    int x = 23;
    cout << linearsearch(arr, sz, x) << endl;

    return 0;
}