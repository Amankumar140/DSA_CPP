// #include<iostream>
// using namespace std;
// int main()
// {
    
//     int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//     for(int i=0; i<3; i++){
//         for(int j=0; j<3; j++){
//             cout<<mat[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     int x= 5;
//      for(int i=0; i<3; i++){
//         for(int j=0; j<3; j++){
//             if(x==mat[i][j]){
//                 cout<<"found at cell :"<< i+1<<","<<j+1<<endl; 
//             }
//         }
//     }


//     return 0;
// }



#include<iostream>
using namespace std;
#include<limits.h>

int maxSumRow(int mat[][3],int n, int m){
    int maxSum=INT_MIN;
    for(int i=0; i<n; i++){
        int rowSum=0;
        for(int j=0; j<m; j++){
            rowSum+=mat[i][j];
        }
        maxSum=max(rowSum,maxSum);
    }
    return maxSum;
}

int maxSumColumn(int mat[][3],int n, int m){
    int maxSum=INT_MIN;
    for(int i=0; i<n; i++){
        int rowSum=0;
        for(int j=0; j<m; j++){
            rowSum+=mat[j][i];
        }
        maxSum=max(rowSum,maxSum);
    }
    return maxSum;
}
int main()
{
    
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3,m=3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<maxSumRow(mat,n,m)<<endl;
    cout<<maxSumColumn(mat,n,m);


    return 0;
}