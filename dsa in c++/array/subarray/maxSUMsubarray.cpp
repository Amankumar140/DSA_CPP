#include <iostream>
using namespace std;
int main()
{
    int a[7] = {3,-4,5,4,-1,7,-8};
     
    int maxsum = 0;
    for (int i = 0; i < 7; i++)
    {
        int currsum = 0;
        for (int j = i; j < 7; j++)
        {
            currsum += a[j];
            maxsum = max(currsum, maxsum);
        }
         
    }
    cout <<maxsum<< endl;
    return 0;
}