// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 0;
//     int *ptr = &a;
//     cout << ptr << endl;
//     cout << ptr++ << endl; // size added of int 
//     cout << ptr << endl;
//     cout << ptr-- << endl;
//     cout << ptr << endl;
//     return 0;
// }

// // use for array printing
// #include<iostream>
// using namespace std;
// int main()
// {
//     int arr[6]={1,3,5,6,7,8};
//     cout<<*arr<<endl;
//     cout<<*(arr+1)<<endl;
//     cout<<*(arr+2)<<endl;
//     cout<<*(arr+3)<<endl;
//     cout<<*(arr+4)<<endl;
//     cout<<*(arr+5)<<endl;
     
//     return 0;
// }


// we cannot add two pointers but subtract them condition sae datatype 
// ptr1-ptr2 = no. of blocks ot datatype

#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int b=80;
    int *ptr=&a;
    int *ptr1=&b;
    cout<<ptr-ptr1<<endl;
    return 0;
}