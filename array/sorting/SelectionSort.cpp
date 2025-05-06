#include <iostream>
using namespace std;
// sort
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int smallIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallIndex])
            {
                smallIndex = j;
            }
        }
        swap(arr[i], arr[smallIndex]);
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
    SelectionSort(arr, 9);
    print(arr, 9);

    return 0;
}