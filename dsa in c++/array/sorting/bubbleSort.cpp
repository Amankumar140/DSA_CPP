#include <iostream>
using namespace std;
// sort
void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= n - 1 - i; j++)
        {
            bool isSwap = false;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
            if (isSwap)
            {
                return;
            }
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 4, 2, 7, 23, 8, 34, 3, 6};
    bubbleSort(arr, 9);
    print(arr, 9);

    return 0;
}