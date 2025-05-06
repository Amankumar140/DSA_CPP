// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[] = {1, 1, 2, 3, 4, 3, 4, 5, 6, 6};
//     int brr[8];
//     int c = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         int found = 0;
//         for (int k = 0; k < c; k++)
//         {

//             if (arr[i] == brr[k])
//             {
//                 found = 1;
//                 break;
//             }
//         }
//         if (!found)
//         {
//             brr[c++]=arr[i];
//         }
//     }
//     for (int i = 0; i < c; i++)
//     {
//         cout << brr[i] << " ";
//     }

//     return 0;
// }

//exclude the duplicate elements
//time=O(n), space=O(n)
#include <iostream>
using namespace std;
int dup(int arr[], int n)
{
    int temp[n];
    int res = 1;
    temp[0] = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (temp[res - 1] != arr[i])
        {
            temp[res] = arr[i];
            res++;
        }
    }
    for (int i = 0; i < res; i++)
    {
        arr[i] = temp[i];
    }
    for (int i = 0; i < res; i++)
    {
        cout << arr[i] << " ";
    }

}
int main()
{
    int arr[] = {1, 4, 4, 5, 5, 5, 7, 7, 8};
    dup(arr, 9);

    return 0;
}

// exclude the duplicate elements
// time=O(n), space=O(1)
// #include <iostream>
// using namespace std;
// int dup(int arr[], int n)
// {
//     int res = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != arr[res - 1])
//         {
//             arr[res] = arr[i];
//             res++;
//         }
//     }
//     return res;
// }
// int main()
// {
//     int x;
//     int arr[] = {1, 4, 4, 5, 5, 5, 7, 7, 8};
//     x = dup(arr, 9);

//     for (int i = 0; i < x; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

