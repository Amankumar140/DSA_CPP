#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums={4,1,2,4,5,5,2};

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]!=nums[j]){
                cout<<nums[i]<<" ";
            }
        }
    }
    return 0;
}