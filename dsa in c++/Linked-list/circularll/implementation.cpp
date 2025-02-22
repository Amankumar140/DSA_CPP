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
void insertathead(node *&head, int val)
{
    node *new_node = new node(val);

    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
}

void insertattail(node *&head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *new_node = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
}
void display(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    do
    {
        cout << temp->val << " "; // Print the value of the current node
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    node *aman = NULL;
    insertathead(aman, 3);
    insertathead(aman, 8);
    insertathead(aman, 5);
    insertathead(aman, 4);
    insertattail(aman,24);
    insertattail(aman,25);
    insertattail(aman,23);
    display(aman);

    return 0;
}