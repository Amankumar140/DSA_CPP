#include<iostream>
using namespace std;
int main()
{
    string s="aman kumar";
     int n=s.size();
     int i=0;
     while(i<n/2){
        char ch=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=ch;
        i++;
     }
     cout<<s;
    return 0;
}