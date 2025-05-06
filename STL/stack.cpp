#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(7);
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<s.size()<<endl;
    return 0;
}