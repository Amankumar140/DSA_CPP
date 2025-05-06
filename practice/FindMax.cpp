#include<iostream>
#include<climits>
using namespace std;
int findMax(int arr[],int n){
    int Max=INT_MIN;
     for(int i=0; i<n; i++){
        Max=max(Max,arr[i]);
     }
     return Max;
}
int main()
{
    int arr[6]={1,2,3,41,5,6};    
    cout<<findMax(arr, 6);

    return 0;
}