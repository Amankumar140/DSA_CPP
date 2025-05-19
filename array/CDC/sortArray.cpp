#include <iostream>
using namespace std;
int main()
{
    int arr[] = {0, 1, 1, 0, 0, 1, 0, 1, 1, 0};
    // int  j=0;
    // for(int i=0; i<10; i++){
    //     if(arr[i]==0){
    //         swap(arr[i],arr[j++]);
    //     }
    // }

    //  for(int i=0; i<10; i++){
    //     cout<<arr[i]<<endl;
    //  }
    // including 2
    int arr1[] = {0, 1, 1, 0, 0, 1, 2, 0, 1, 1, 0, 2, 2};
    int left = 0, end = 12;
    int i = 0;
    while (i<= end)
    {
        if (arr1[i] == 1)
        {
            i++;
            continue;
        }
        if (arr1[i] == 0)
        {
            swap(arr1[i], arr1[left++]);
            i++;
        }
        else if (arr1[i] == 2)
        {
            swap(arr1[i], arr1[end--]);
             
        }
         
    }

    for (int idx = 0; idx < 13; idx++)
    {
        cout << arr1[idx] << endl;
    }
    return 0;
}