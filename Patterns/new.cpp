 // 
//  *****
//   *** 
//    *

// void nStarTriangle(int n) {
   
//     for(int i=0; i<n; i++){
//         for(int j=0; j<i; j++){
//             cout<<" ";
//         }
//         for(int  j=0; j<2*n-(2*i+1); j++){
//             cout<<"*";
//         }
//         for(int j=0; j<i; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }

//     A
//   A B A
// A B C B A

// void alphaHill(int n) {
//     for(int i=1; i<=n; i++){
        
//         for(int j=1; j<=n-i; j++){
//             cout<<" "<<" ";
//         }
//         int x= (2*i+1)/2;
//         char ch='A';
//         for(int j=1; j<=2*i-1; j++){
//             cout<<ch<<" ";
//             if(j<x){ch++;}
//             else{ch--;}
            
//         }
//         for(int j=1; j<=n-i; j++){
             
//             cout<<" "<<" ";
//         }
//         cout<<endl;
//     }
// }