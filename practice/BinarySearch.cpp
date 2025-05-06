#include<iostream>
using namespace std;
int maxfind(int arr[], int x,int n){
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            return i+1;
        }
    }
    return -1;
}
int main()
{
    int arr[8];
    for(int i=0;i<8; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<maxfind(arr,6,8)<<endl;

    return 0;
}