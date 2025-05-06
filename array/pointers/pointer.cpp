#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *ptr = &a;
    int **ptr1 = &ptr;
    cout << &a << endl;     // address of a
    cout << ptr << endl;    // address of a
    cout << &ptr << endl;   // address of ptr
    cout << ptr1 << endl;   // address of ptr
    cout << &ptr1 << endl;  // address of ptr1
    cout << a << endl;      // value of a
    cout << *ptr << endl;   // value of a
    cout << *ptr1 << endl;  // address of a
    cout << **ptr1 << endl; // value of a
    return 0;
}