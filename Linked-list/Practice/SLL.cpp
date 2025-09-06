#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void InsertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void InsertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int deleteNodeAtK(Node *&head, int k)
{
    if (!head->next)
    {
        int x = head->data;
        free(head);
        return 0;
    }
    Node *temp = head;
    for (int i = 0; i < k - 1; i++)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    int x = deleteNode->data;
    temp->next = temp->next->next;
    return x;
}

// reverse of linkedlist
Node *Reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr)
    {
        Node *NEXT = curr->next;
        curr->next = prev;

        prev = curr;
        curr = NEXT;
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, 2);
    InsertAtHead(head, 3);
    InsertAtHead(head, 4);
    InsertAtHead(head, 5);
    InsertAtEnd(head, 8);
    InsertAtEnd(head, 9);
    InsertAtEnd(head, 10);
    printLL(head);
    // cout << deleteNodeAtK(head, 3) << endl;
    // printLL(head);
    head = Reverse(head);
    printLL(head);
    return 0;
}
