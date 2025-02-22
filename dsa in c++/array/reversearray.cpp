#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int reverse(int arr[], int sz)
{
    int start = 0;
    int end = sz - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int arr[] = {2, 4, 5, 67, 12,17};
    int sz = 6;
    cout << "reverse of array is " << endl;
    reverse(arr, sz);
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " " << endl;
    }

    return 0;
}
