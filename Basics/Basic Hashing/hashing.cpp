// number hashing

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int hash[13] = {0};

//     for (int i = 0; i < n; i++)
//     {
//         hash[arr[i]] += 1;
//     }
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int num;
//         cin >> num;
//         cout<<hash[num]<<endl;
//     }
//     return 0;
// }

// // charachter hashing
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cin>>s;
//     int hash[256]={0};
//     for(int i=0; i<s.size(); i++){
//         hash[s[i]]++;
//     }
//     int q; 
//     cin>>q;
//     while(q--){
//         char ch;
//         cin>>ch;
//         cout<<hash[ch]<<endl;
//     }

//     return 0;
// }

//using map
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     map<int,int>mpp;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         mpp[arr[i]]++;
//     }

     
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int num;
//         cin >> num;
//         cout<<mpp[num]<<endl;
//     }
//     return 0;
// }

// charachter hashing
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    map<char, int> mpp;
    for(int i=0; i<s.size(); i++){
        mpp[s[i]]++;
    }
    int q; 
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        cout<<mpp[ch]<<endl;
    }

    return 0;
}