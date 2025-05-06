#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(8);
    l.push_back(7);
    l.push_back(5);
    l.push_back(4);
    l.push_front(9);
    // l.pop_back();
    // l.pop_front();
    l.sort();
    l.reverse();

    for( auto i: l){
        cout<<i<<" ";
    }
    return 0;
}