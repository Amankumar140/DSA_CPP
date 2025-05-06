#include<iostream>
using namespace std;

void sort(int arr[], int n) {
    int i = 0;
    while(i < n) {
        int correct = arr[i] - 1;
         
        if (arr[i] >= 1 && arr[i] <= n + 2 && correct < n && arr[i] != arr[correct]) {
            swap(arr[i], arr[correct]);
        } else {
            i++;
        }
    }
}

void find(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n + 2; i++) {
        if (i < n && arr[i] != i + 1) {
            cout << "Missing: " << i + 1 << endl;
            count++;
        } else if (i >= n) {
            
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (arr[j] == i + 1) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Missing: " << i + 1 << endl;
                count++;
            }
        }
        if (count == 2) break;  
    }
}

int main() {
    int arr[9] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int n = 9;

    sort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    find(arr, n);

    return 0;
}
