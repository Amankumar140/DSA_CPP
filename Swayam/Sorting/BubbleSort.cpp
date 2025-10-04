#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// recursive code for bubble sort

void BubbleSortRec(int arr[], int n)
{
    if (n == 1)
        return;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            swap(arr[i + 1], arr[i]);
            count++;
        }
    }
    // for not swap occurs
    if (count == 0)
        return;
    BubbleSortRec(arr, n - 1);
}

int main()
{
    int arr[] = {2, 1, 8, 12, 3, 9, 7, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    // BubbleSort(arr, n);
    BubbleSortRec(arr, n);
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}