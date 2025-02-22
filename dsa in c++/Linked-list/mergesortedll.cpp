#include <iostream>
using namespace std;
#include <vector>
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

void insertatHead(node *&head, int val)
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

node *merge(node *head1, node *head2)
{
    node *dummyhead = new node(-1);
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummyhead;
    while (ptr1 && ptr2)
    {
        if (ptr1->val < ptr2->val)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if (ptr1)
    {
        ptr3->next = ptr1;
    }
    else
    {
        ptr3->next = ptr2;
    }
    return dummyhead->next;
}

node *mergeK(vector<node *> &lists)
{
    if (lists.size() == 0)
    {
        return NULL;
    }
    while (lists.size() > 1)
    {
        node *merge_a = merge(lists[0], lists[1]);
        lists.push_back(merge_a);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
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

int main()
{
    node *aman = NULL;
    insertatHead(aman, 4);
    insertatHead(aman, 7);
    insertatHead(aman, 8);
    insertatHead(aman, 17);
    insertatHead(aman, 26);
    insertatHead(aman, 35);
    node *amu = NULL;
    insertatHead(amu, 14);
    insertatHead(amu, 17);
    insertatHead(amu, 28);
    insertatHead(amu, 127);
    insertatHead(amu, 226);
    insertatHead(amu, 325);
    node *akhil = NULL;
    insertatHead(akhil, 1);
    insertatHead(akhil, 9);
    insertatHead(akhil, 18);
    display(aman);
    display(akhil);
    display(amu);
    vector<node *> merged;
    merged.push_back(amu);
    merged.push_back(aman);
    merged.push_back(akhil);
    node *ak = mergeK(merged);
    display(ak);

    return 0;
}