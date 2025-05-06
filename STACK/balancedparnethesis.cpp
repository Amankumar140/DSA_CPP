#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
bool check(char *ak)
{
    int n = strlen(ak);
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        if (ak[i] == '(' || ak[i] == '{' || ak[i] == '[')
        {
            s.push(ak[i]);
        }
        else if (ak[i] == ')' ||  
                 ak[i] == '}' ||
                 ak[i] == ']')
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            if ((ak[i] == ')' && top == '(') ||
                (ak[i] == '}' && top == '{') ||
                (ak[i] == ']' && top == '['))
            {
                s.pop();
            }
        }
        else
        {
            s.pop();
        }
    }
    return s.empty() ? true : false;
}
int main()
{
    char ak[200];
    gets(ak);
    cout << check(ak);
    return 0;
}