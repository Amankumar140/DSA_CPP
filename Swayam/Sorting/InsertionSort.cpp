#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

// recursive code for bubble sort

void insertionSortRec(int arr[], int n, int i = 0)
{
    if (i == n)
        return;

    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j -= 1;
    }
    arr[j + 1] = key;

    insertionSortRec(arr, n, i + 1);
}

int main()
{
    int arr[] = {2, 1, 8, 12, 3, 9, 7, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    // insertionSort(arr, n);
    insertionSortRec(arr, n);
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}