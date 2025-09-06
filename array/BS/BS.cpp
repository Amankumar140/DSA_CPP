#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int lowerBound(vector<int> &arr, int target)
{
    int l = 0, e = arr.size() - 1;
    int ans = 0;
    while (l <= e)
    {
        int mid = l + (e - l) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int x = 9;
    cout << lowerBound(arr, x) << endl;
    return 0;
}