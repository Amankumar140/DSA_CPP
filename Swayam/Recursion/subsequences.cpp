#include <iostream>
using namespace std;
#include <vector>

void printSubsequences(vector<int> &arr, vector<int> ans, int idx = 0, int l = 0)
{
    if (idx == arr.size())
    {
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    // include
    ans.push_back(arr[idx]);
    printSubsequences(arr, ans, idx + 1, l + 1);
    ans.pop_back();
    // not include
    printSubsequences(arr, ans, idx + 1, l);
}

// for strings

void printSubSeq(string s, string curr = "", int i = 0)
{
    if (i >= s.length())
    {
        cout << curr << endl;
        return;
    }
    // include
    ;
    printSubSeq(s, curr + s[i], i + 1);
    printSubSeq(s, curr, i + 1);
}

void printSubSeqPattern(string s, string curr = "", int i = 0)
{
    if (i >= s.length())
    {
        cout << curr << endl;
        return;
    }
    // include
    printSubSeqPattern(s, curr + s[i], i + 1);
    // exclude
    printSubSeqPattern(s, curr + "1", i + 1);
}
// without extra string
void printSubSeqPattern1(string s, int i = 0)
{
    if (i >= s.length())
    {
        cout << s << endl;
        return;
    }
    // include
    printSubSeqPattern1(s, i + 1);
    // exclude
    char temp = s[i];
    s[i] = '1';
    printSubSeqPattern1(s, i + 1);
    s[i] = temp;
}

// permutation

void permutation(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        for (int i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(arr[l], arr[i]);
        permutation(arr, l + 1, r);
        swap(arr[l], arr[i]);
    }
}

int main()
{
    int n;
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    // printSubsequences(arr, ans);
    string s = "ABC";
    // printSubSeq(s);
    // printSubSeqPattern(s);
    // cout << endl;
    // printSubSeqPattern1(s);
    permutation(arr, 0, arr.size() - 1);

    return 0;
}