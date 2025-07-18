// most asked questions.....

// interview questions.........

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {2, 5, 1, 7, 10};

    int k = 14;

    // find the max len of subarray that have the sum<=k

    // first approach is the brute
    // 2nd one is sliding window...

    // two concep, expand for right and shrink for the left window

    int l = 0, r = 0;

    int sum = 0;
    int maxlen = 0;
    while (r < 5)
    {
        sum += arr[r];
        if (sum > k)
        {
            sum -= arr[l++];
        }
        if (sum <= k)
        {
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
    }
    cout << maxlen << endl;

    return 0;
}