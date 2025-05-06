#include<iostream>
using namespace std;
void change(int &b){ // &b --> is alias 
    b=35;
}
int main()
{
    int a=10;
    change(a);
    cout<<a;

    return 0;
}