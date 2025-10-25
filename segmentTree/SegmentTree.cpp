#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int arr[100], seg[4 * 100];

void build(int idx, int low, int high)
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r)
{
    // completely inside
    if (low >= l && high <= r)
    {
        return seg[idx];
    }
    // outside
    if (high < l || low > r)
        return INT_MIN;

    // overlapping
    int mid = (low +  high) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return max(left, right);
}

int main()
{
    int n;
    cout << "Enter n :";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);
    cout << query(0, 0, n - 1, 2, 3) << endl;
    return 0;
}