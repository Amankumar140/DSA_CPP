// // brute approach O(n^2)
// #include <iostream>
// #include <vector>
// using namespace std;
// int major(vector<int> nums)
// {
//     int n = nums.size();
//     for (int val : nums)
//     {
//         int freq = 0;
//         for (int el : nums)
//         {
//             if (el == val)
//             {
//                 freq++;
//             }
//         }
//         if (freq > n / 2)
//         {
//             return val;
//         }

//     }

// }
// int main()
// {
//     vector<int> nums = {2, 2, 2,22,22,22,22};
//     cout<<major(nums)<<endl;

//     return 0;
// }

// // // optimise approach
// // #include <iostream>
// // #include <vector>
// // #include<stdlib.h>
// // using namespace std;
// // void sorting(vector<int> &nums)
// // {
// //     int n = nums.size();
// //     for (int i = 0; i < n; i++)
// //     {
// //         for (int j = 0; j < n - 1 - i; j++)
// //         {
// //             if (nums[j] > nums[j + 1])
// //             {
// //                 int temp = nums[j];
// //                 nums[j] = nums[j + 1];
// //                 nums[j + 1] = temp;
// //             }
// //         }
// //     }
// // }
// // int major(vector<int> nums)
// // {
// //     int n = nums.size();
// //     int ans=nums[0];
// //     int freq=1;
// //     for(int i=1; i<n; i++){
// //         if(nums[i]==nums[i-1]){
// //             freq++;
// //         }
// //         else{
// //             freq=1;
// //             ans=nums[i];
// //         }

// //         if(freq>n/2){
// //             return ans;
// //         }
// //     }
// //     return -1;
// // }

// // int main()
// // {
// //     vector<int> num = {2, 2, 1, 1, 1, 1};
// //     sorting(num);
// //     cout<<major(num)<<" "<<endl;

// //     return 0;
// // }

// brute approach O(n^2)
// #include <iostream>
// #include <vector>
// using namespace std;
// int major(vector<int> nums)
// {
//     int n = nums.size();
//     for (int val : nums)
//     {
//         int freq = 0;
//         for (int el : nums)
//         {
//             if (el == val)
//             {
//                 freq++;
//             }
//         }
//         if (freq > n / 2)
//         {
//             return val;
//         }
//     }
// }
// int main()
// {
//     vector<int> nums = {2, 2, 2, 22, 22, 22, 22};
//     cout << major(nums) << endl;

//     return 0;
// }

// moore's approach
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int major(vector<int> nums)
{
    int n = nums.size();
    int freq = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

int main()
{
    vector<int> num = {2, 2, 1, 1, 1, 1};
     
    cout << major(num) << " " << endl;

    return 0;
}