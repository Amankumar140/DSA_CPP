// constant window...

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {-1, 2, 3, 3, 4, 5, -1};
    int k = 4;

    // pick up max sum of subarray of size k

    int l = 0, r = k - 1;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int maxsum = sum;
    while (r < 7)
    {
        sum -= arr[l];
        l++;
        r++;
        sum += arr[r];
        maxsum = max(maxsum, sum);
    }

    cout << maxsum << endl;

    return 0;
}