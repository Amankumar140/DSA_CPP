// target sum brute approach O(n^2)
#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> nums, int target)
{
    vector<int> ans;
    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[i + 1] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums ={2,4,6,7,8,9,12,23};// 5,6
    int target = 21;
    vector <int> ans=pairsum(nums,target);
    cout<<ans[0]<<" "<< ans[1]<<endl;

    return 0;
}


// target sum ==optimal approach O(n)
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> pairsum(vector<int> nums, int target)
// {
//     vector<int> ans;
//     int n= nums.size();
//     int i=0, j=n-1;
//     while(i<j){
//         int pairsum=nums[i]+nums[j];
//         if(pairsum<target){
//             i++;
//         }
//         else if ( pairsum>target){
//             j--;
//         }
//         else {
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }
//     }
//     return ans;
// }
// int main()
// {
//     vector<int> nums ={2,4,6,7,8,9,12,23};// 5,6
//     int target = 21;
//     vector <int> ans=pairsum(nums,target);
//     cout<<ans[0]<<" "<< ans[1]<<endl;

//     return 0;
// }