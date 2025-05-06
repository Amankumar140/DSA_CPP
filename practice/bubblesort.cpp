#include<iostream>
using namespace std;
void sort(int arr[],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    sort(arr,6);
 
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}