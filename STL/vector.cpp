#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v1={2,3,4,5,6,7,8,};
    vector<int> v;
    v.push_back(5);
    v.push_back(9);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    // sort(v.begin(),v.end());
    // reverse(v.begin(),v.end());

    //v1.swap(v);
    // print v
    for(auto i=v.begin(); i!=v.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    // print v1
     for(auto i=v1.begin(); i!=v1.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    // reverse iterators
    for( auto i=v.rbegin(); i!=v.rend(); i++){
        cout<<*i<<" ";
    }


    return 0;
}