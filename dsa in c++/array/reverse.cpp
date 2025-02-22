// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     cout << "Enter the elements :" << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n/2; i++)
//     {
//         int swap = a[i];
//         a[i] = a[n-i-1];
//         a[n - i - 1] = swap;

//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] <<" ";
//     }

//     return 0;
// }

#include <iostream>
using namespace std;
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void reverse(int arr[], int n)
{
    // int j=n;
    for (int i = 0; i <=n / 2; i++)
    {
        swap(arr[i], arr[n - i-1]);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    display(arr,7);
    reverse(arr, 7);
    cout<<endl;
    display(arr,7);
    return 0;
}