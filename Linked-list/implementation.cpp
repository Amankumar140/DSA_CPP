#include <iostream>
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
void insertatend(node *&head, int val)
{
    node *new_node = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
// void display(node *head)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << "->";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }

void display(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->val << " ";
    display(head->next);
}
void REVERSEdisplay(node *head)
{
    if (head == NULL)
    {
        return;
    }

    REVERSEdisplay(head->next);
    cout << head->val << " ";
}

void reverse(node*p, node *&head)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverse(p->next,head);
    p->next->next=p;
    p->next=NULL;
}
int main()
{
    node *head = NULL;
    insertatend(head, 12);
    insertatend(head, 122);
    insertatend(head, 11);
    insertatend(head, 13);
    insertatend(head, 14);
    insertatend(head, 15);
    display(head);
    cout << endl;
    REVERSEdisplay(head);
    cout << endl;
    reverse(head, head);
    display(head);

    return 0;
}