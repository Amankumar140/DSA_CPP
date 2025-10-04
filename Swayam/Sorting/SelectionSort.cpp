#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[idx])
            {
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
}

// recursive code for bubble sort

void selectionSortRec(int arr[], int n, int i = 0)
{
    if (i == n - 1)
        return;

    int idx = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[idx] > arr[j])
        {
            idx = j;
        }
    }
    swap(arr[i], arr[idx]);

    selectionSortRec(arr, n, i + 1);
}

int main()
{
    int arr[] = {2, 1, 8, 12, 3, 9, 7, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    // selectionSort(arr, n);
    selectionSortRec(arr, n);
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}