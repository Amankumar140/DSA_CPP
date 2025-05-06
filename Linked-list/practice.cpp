#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertionAtBeg(Node *&head, int data)
{
    Node *new_node = new Node(data);

    new_node->next = head;
    head = new_node;
}

void insertAtEnd(Node *&head, int data)
{
    Node *new_node = new Node(data);
    Node *temp = head;
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

// delete from alternate position from 2nd

void deleteFrom2ndAlternate(Node *&head)
{
    Node *curr = head;
    while (curr->next != NULL && curr->next->next != NULL)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        curr = curr->next;
    }
}

void insertAtK(Node *&head, int data, int pos)
{
    Node *new_node = new Node(data);
    Node *temp = head;
    int curr = 0;
    while (curr < pos - 1)
    {
        temp = temp->next;
        curr++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// reverse the ll
Node *reverse(Node *&head)
{
    Node *curr, *next, *prev;
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *ak = NULL;
    insertionAtBeg(ak, 4);
    insertionAtBeg(ak, 5);
    insertionAtBeg(ak, 6);
    insertionAtBeg(ak, 7);
    insertionAtBeg(ak, 8);
    insertAtEnd(ak, 5);
    insertAtEnd(ak, 6);
    insertAtEnd(ak, 7);
    insertAtEnd(ak, 8);
    insertAtEnd(ak, 9);
    insertAtK(ak, 23, 3);
    display(ak);
    reverse(ak);
    display(ak);
    deleteFrom2ndAlternate(ak);

    display(ak);

    return 0;
}