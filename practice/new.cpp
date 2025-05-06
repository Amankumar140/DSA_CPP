#include<iostream>
using namespace std;
int sum(int n){
    int sum=0;
    while(n>0){
        sum+=n;
        n--;
    }

    return sum;
}

void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;

}

int main()
{
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
    int a=3,b=7;
    cout<<a<<b;

    swap(a,b);
    cout<<a<<b;
    return 0;
}