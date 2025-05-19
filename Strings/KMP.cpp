#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s = "ababab";
    vector<int> lps(s.size(), 0);
    int pre = 0;
    int suf = 1;
    while (suf < s.size())
    {
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
    for (int i = 0; i < lps.size(); i++)
    {
        cout << lps[i] << endl;
    }

    return 0;
}