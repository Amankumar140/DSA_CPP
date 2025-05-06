// //insertion in linked list

// #include <iostream>
// using namespace std;
// class node
// {
// public:
//     int val;
//     node *next;
//     node(int data)
//     {
//         val = data;
//         next = NULL;
//     }
// };

// void insert(node *&head, int val)
// {
//     node *new_node = new node(val);
//     new_node->next = head;
//     head = new_node;
// };

// void display(node *head)
// {
//     node *current = head;
//     while (current != NULL)
//     {
//         cout << current->val << "->";
//         current = current->next;
//     }
//     cout<<"NULL"<<endl;
// }
// int main()
// {
//     node* x = NULL;
//     insert(x, 2);
//     display(x);
//     insert(x, 3);
//     display(x);
//     insert(x, 4);
//     display(x);

//     return 0;
// }

// insert at last of linked list

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

void insertatlast(node *&head, int val)
{
    node *akhil = new node(val);
    node *aman = head;

    while (aman->next != NULL)
    {
        aman = aman->next;
    }
    aman->next = akhil;
}
void insertathead(node *&head, int val)
{
    node *ak = new node(val);
    ak->next = head;
    head = ak;
}
void insertatK(node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertathead(head, val);
        return;
    }
    node *new_node = new node(val);
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
    node *akki = head;
    while (akki!= NULL)
    {
        cout << akki->val << " ->";
        akki = akki->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *aman = NULL;
    insertathead(aman, 4);
    display(aman);
    insertathead(aman, 5);
    display(aman);
    insertathead(aman, 7);
    display(aman);
    insertatlast(aman, 8);
    insertathead(aman, 23);
    display(aman);
    insertatlast(aman, 56);
    insertathead(aman, 41);
    display(aman);
    insertatlast(aman, 33);
    insertatK(aman, 78, 5);
    display(aman);

    return 0;
}