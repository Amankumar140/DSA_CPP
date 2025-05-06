#include<iostream>
using namespace std;
int main()
{
    int n=15;
    int cnt=0;
    for(int i=1; i<=32; i++){
        if((n>>i)&1){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}