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

void insertathead(node *&head, int data)
{
    node *new_node = new node(data);
    new_node->next = head;
    head = new_node;
}
void insertattail(node *&head, int x)
{
    node *new_node = new node(x);

    node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertatK(node *&head, int y, int pos)
{
    if (pos == 0)
    {
        insertathead(head, y);
        return;
    }
    node *new_node = new node(y);
    node *temp = head;
    int curr_pos = 0;
    while (curr_pos != pos - 1)
    {
        temp = temp->next;
        curr_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void display(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *aman = NULL;
    insertathead(aman, 10);
    insertattail(aman, 34);
    insertathead(aman, 10);
    insertattail(aman, 34);
    insertathead(aman, 10);
    insertattail(aman, 34);
    insertatK(aman, 23, 4);

    display(aman);
    return 0;
}