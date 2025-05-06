#include <iostream>
using namespace std;
class stack
{
public:
    int arr[100];
    int size = 0;
    int top = -1;
    void push(int val)
    {
        if (size == 100)
        {
            cout << "overflow" << endl;
            return;
        }
        arr[++top] = val;
        size++;
    }
    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        size--;
        return (arr[top--]);
    }

    int peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == 100;
    }
};

int main()
{
    stack s;
    string str = "(([]]{]}))";
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        if ((ch == ')' && s.peek() == '(') || (ch == '}' && s.peek() == '{') || (ch == ']' && s.peek() == '['))
        {
            s.pop();
        }
    }

    if (s.size == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
