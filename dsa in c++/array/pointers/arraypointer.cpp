#include<iostream>
using namespace std;
int main()
{
    int arr[4]={12,23,34,45};
    cout<<arr<<endl; // constant pointer means not mutable...
    cout<<*arr<<endl; // print 0th index

    return 0;
}