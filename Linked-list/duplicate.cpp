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
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void d_duplicate(node *&head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        while (temp->next && temp->val == temp->next->val)
        {
            node *dup = temp->next;
            temp->next = temp->next->next;
            free(dup);
        }
        temp = temp->next;
    }
}

void reverse(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    reverse(head->next);
    cout << head->val << "->";
}

int main()
{
    node *ak = NULL;
    insertatend(ak, 1);
    insertatend(ak, 2);
    insertatend(ak, 2);
    insertatend(ak, 3);
    insertatend(ak, 3);
    insertatend(ak, 3);
    insertatend(ak, 4);
    display(ak);
    reverse(ak);
    cout<<endl;
    d_duplicate(ak);
    display(ak);
    return 0;
}