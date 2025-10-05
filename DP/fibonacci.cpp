#include <iostream>
using namespace std;
#include <vector>
// using memoization
int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

// using tabulation
// SC O(n)
int fibonacciTab(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// memory optimisation
int fibonacciTab2(int n)
{
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonacci(n, dp) << endl;
    cout << fibonacciTab(n, dp) << endl;
    cout << fibonacciTab2(n) << endl;
    return 0;
}