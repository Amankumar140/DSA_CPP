// #include <iostream>
// using namespace std;
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void reverse(int arr[], int l,int m)
// {
//     if(l>=m){
//         return;
//     }
//     swap(arr[l], arr[m]);
//     reverse(arr,l+1,m-1);
// }
// int main()
// {
//     int arr[10]={1,2,3,4,5,6,7};
//     reverse(arr,0,6);
//     for(int i=0; i<7; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void reverse(int arr[], int i,int n)
// {
//     if(i>=n/2){
//         return;
//     }
//     swap(arr[i], arr[n-i-1]);
//     reverse(arr,i+1,n);
// }
// int main()
// {
//     int arr[7]={1,2,3,4,5,6,7};
//     reverse(arr,0,7);
//     for(int i=0; i<7; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// check palidrome
// #include <iostream>
// #include <string.h>
// using namespace std;

// void pallidrome(char str[], int i, int n)
// {
//     if (i >= n / 2)
//     {
//         return;
//     }
//     if (str[i] != str[n - i - 1])
//     {
//         cout << "not " << endl;
//         return;
//     }
//     else
//     {
//         cout << "yes" << endl;
//         return;
//     }
//     pallidrome(str, i + 1, n);
// }
// int main()
// {
//     char str[] = {"hello"};
//     int n = strlen(str);
//     pallidrome(str, 0, n);
//     return 0;
// }

// fibonacci series
#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibo(n-1) + fibo(n - 2);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fibo(i) << " ";
    }
    return 0;
}