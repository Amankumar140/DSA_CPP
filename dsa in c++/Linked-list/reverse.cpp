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
void insertattail(node *&head, int val)
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

node *reversal(node *&head)
{
    node *currptr = head;
    node *prevptr = NULL;
    while (currptr != NULL)
    {
        node *nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    node *new_head = prevptr;
    return new_head;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "-> ";
        temp = temp->next;
    }
    cout << " NULL" << endl;
}

node *recursionreverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *new_head = recursionreverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

void reverseprint(node *head)
{

    if (head == NULL)
    {
        return;
    }
    reverseprint(head->next);
    cout << head->val << " ";
}

// given the head of a linked list, reverse the nodes of the list k at a time , and return the modified list

node *reversell(node *&head, int k)
{
    node *prepvtr = NULL;
    node *currptr = head;
    int counter = 0;
    while (currptr != NULL && counter < k)
    {
        node *nextptr = currptr->next;
        currptr->next = prepvtr;
        prepvtr = currptr;
        currptr = nextptr;
        counter++;
    }

    if (currptr != NULL)
    {
        node *new_node = reversell(currptr, k);
        head->next=new_node;
    }
    return prepvtr;
}
int main()
{
    node *aman = NULL;
    insertattail(aman, 23);
    insertattail(aman, 24);
    insertattail(aman, 25);
    insertattail(aman, 26);
    insertattail(aman, 29);
    insertattail(aman, 217);
    insertattail(aman, 227);
    insertattail(aman, 257);
    insertattail(aman, 2777);
    insertattail(aman, 279);
    display(aman);
    // aman = reversal(aman);
    // display(aman);
    // aman = recursionreverse(aman);
    // display(aman);
    // reverseprint(aman);
    aman=reversell(aman, 2);
    display(aman);

    return 0;
}