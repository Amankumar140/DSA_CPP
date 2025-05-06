#include<iostream>
using namespace std;
void change(int &b){ // &b --> is alias 
    b=65;
}
int main()
{
    int a=10;
    change(a);
    cout<<a;

    return 0;
}