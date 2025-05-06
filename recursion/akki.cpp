// print n times name
// #include<iostream>
// using namespace std;
// void printf(int n){
//     if(n==0){
//         return;
//     }
//     cout<<"aman"<<endl;
//     printf(n-1);

// }
// int main()
// {
//     int n;
//     cin>>n;
//     printf(n);
//     return 0;
// }

//print 1-n
// #include <iostream>
// using namespace std;
// void printf(int n, int i)
// {
//     if (i > n)
//     {
//         return;
//     }
//     cout << i << endl;
//     return printf(n, i + 1);
// }
// int main()
// {
//     int n;

//     cin >> n;
//     printf(n, 1);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void printf(int n)
// {
//     if (n<=0)
//     {
//         return;
//     }
//     cout << n << endl;
//     return printf(n-1);
// }
// int main()
// {
//     int n;

//     cin >> n;
//     printf(n);
//     return 0;
// }


//print 1-n
// #include <iostream>
// using namespace std;
// void printf(int n, int i)
// {
//     if (i<1)
//     {
//         return;
//     }
//     printf(n, i - 1);
//     cout << i << endl;
    
// }
// int main()
// {
//     int n;

//     cin >> n;
//     printf(n, n);
//     return 0;
// }


// sum of natural no...

#include <iostream>
using namespace std;
int sum(int n)
{
    
    if (n<0)
    {
        return 0;
    }
     
    return(n+sum(n-1));
    
}
int main()
{
    int n;

    cin >> n;
    cout<<sum(n)<<endl;
    return 0;
}