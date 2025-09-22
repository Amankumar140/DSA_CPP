#include <bits/stdc++.h>
using namespace std;

vector<int> BIT; // Fenwick Tree array

void update(int i, int val, int n) {
    while (i <= n) {
        BIT[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1); // 1-based indexing
    for (int i = 1; i <= n; i++) cin >> arr[i];

    BIT.assign(n+1, 0);

    // build Fenwick Tree
    for (int i = 1; i <= n; i++) {
        update(i, arr[i], n);
    }

    // Queries
    cout << "Sum of first 5 elements: " << query(5) << "\n";
    cout << "Sum from index 3 to 7: " << query(7) - query(2) << "\n";

    // Update
    update(3, 5, n); // add +5 at index 3
    cout << "After update, sum of first 5: " << query(5) << "\n";

    return 0;
}
