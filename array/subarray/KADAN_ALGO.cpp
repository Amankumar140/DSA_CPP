#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    int a[7] = {3, -4, 5, 4, -1, 7, -8};
    int currsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < 7; i++)
    {
        currsum += a[i];
        maxsum = max(currsum, maxsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    cout << maxsum;
    return 0;
}