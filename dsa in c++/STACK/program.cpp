// #include <iostream>
// #include <stack>
// #include <string.h>
// using namespace std;

// void reverse(char ch[], int n)
// {
//     stack<char> s;
//     // loop for push
//     for (int i = 0; i < n; i++)
//     {

//         s.push(ch[i]);
//     }
//     // for pop operation
//     for(int i=0; i<n; i++){
//         ch[i]=s.top(); // overwrite
//         s.pop(); // pop
//     }
// }
// int main()
// {
//     char ch[500];
//     cout << "Enter string :";
//     gets(ch);
//     reverse(ch, strlen(ch));
//     puts(ch);

//     return 0;
// }

// reverse a linked list using stack

#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertathead(node *&head, int val)
{
    node *new_node = new node(val);
    new_node->next = head;
    head = new_node;
}

void reverselinkedlist(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    stack<node *> s;
    node *temp = head;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *aman = NULL;
    insertathead(aman, 40);
    insertathead(aman, 42);
    insertathead(aman, 43);
    insertathead(aman, 48);
    insertathead(aman, 49);
    display(aman);
    reverselinkedlist(aman);
    display(aman);

    return 0;
}