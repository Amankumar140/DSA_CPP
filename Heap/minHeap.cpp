#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>
class minHeap
{
public:
    int *arr;
    int capacity;
    int size;

    minHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void insert(int val)
    {
        if (size == capacity)
        {
            return;
        }
        size++;
        arr[size - 1] = val;
        for (int i = size - 1; i != 0 && arr[i] < arr[parent(i)];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void printHeap()
    {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void minHeapIfy(int i)
    {
        int lt = left(i), rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[i])
        {
            smallest = lt;
        }
        if (rt < size && arr[rt] < arr[smallest])
        {
            smallest = rt;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapIfy(smallest);
        }
    }

    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[size];
        }

        swap(arr[0], arr[size - 1]);
        size--;
        minHeapIfy(0);
        return arr[size];
    }

    void decreaseKey(int i, int value){
        arr[i]=value;
        while(i!=0 && arr[parent(i)]> arr[i]){
            swap(arr[parent(i)], arr[i]);
            i=parent(i);
        }
    }

    void deletion( int idx){
        decreaseKey(idx, INT_MIN);
        extractMin();
    }

    void buildHeap(){
        for(int i=(size-1)/2; i>=0; i--){
            minHeapIfy(i);
        }
    }

    ~minHeap()
    {
        delete[] arr; // Free memory to avoid leak
    }
};

int main()
{
    minHeap pq(10);
    pq.insert(2);
    pq.insert(3);
    pq.insert(1);
    pq.insert(8);
    pq.insert(4);
    pq.insert(6);
    pq.printHeap();

    // cout << pq.extractMin() << endl;
    // cout << pq.extractMin() << endl;

    // pq.decreaseKey(3,16);
    // pq.printHeap();
    // pq.deletion(3);


    pq.printHeap();
    return 0;
}


// only for build heap
// int main()
// {
//     minHeap pq(10);

//     // Fill array manually without using insert()
//     pq.arr[0] = 10;
//     pq.arr[1] = 20;
//     pq.arr[2] = 65;
//     pq.arr[3] = 30;
//     pq.arr[4] = 40;
//     pq.arr[5] = 50;
//     pq.size = 6; // important: set the size

//     cout << "Before buildHeap(): ";
//     pq.printHeap();

//     pq.buildHeap(); // convert the array to a valid min-heap

//     cout << "After buildHeap(): ";
//     pq.printHeap();

//     return 0;
// }
