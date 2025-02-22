


#include<iostream>
using namespace std;

// brute force approach;
int gcd(int n,int m){
    int gcd=1;
    for(int i=1; i<=min(n,m); i++){
        if(n%i==0 && m%i==0){
            gcd=i;
        }
    }
     return gcd;
}
// optimal approach
int gcd2(int &a,int &b){
    while(a>0 &&  b>0 ){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    if(a==0){return b;}
    return a;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<gcd2(n,m);
    
    return 0;
}