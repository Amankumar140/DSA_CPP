#include <iostream>
using namespace std;

class maxheap
{
public:
    int size;
    int capacity;
    int *arr;
    maxheap(int n)
    {
        arr = new int[n];
        size = 0;
        capacity = n;
    }

    void buildMaxHeap(int arr[], int n)
    {
        for (int i = (n - 2) / 2; i >= 0; i--)
        {
            maxHeapIfy(arr, n, i);
        }
    }

    void maxHeapIfy(int arr[], int n, int i)
    {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
            left = largest;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapIfy(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n)
    {
        buildMaxHeap(arr, n);
        for (int i = n - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);
            maxHeapIfy(arr, i, 0);
        }
    }
};

int main()
{
    int arr[] = {10, 3, 5, 30, 2, 7, 6, 8, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxheap h(n);
    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    h.heapSort(arr, n);

    cout << "Sorted array (Heap Sort):\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}