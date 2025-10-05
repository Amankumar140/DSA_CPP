#include <bits/stdc++.h>
using namespace std;
vector<int> bit;

void update(int i, int val, int n)
{
    while (i <= n)
    {
        bit[i] += val;
        i += (i & -i);
    }
}

int querySum(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin >> n;
    cout<<"Enter ele: ";
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    bit.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        update(i, arr[i], n);
    }
    cout << querySum(3) << endl;
    return 0;
}
