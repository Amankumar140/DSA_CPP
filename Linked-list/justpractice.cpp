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
void insertathead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
void insertionattail(Node *&head, int val)
{
    Node* new_node=new Node(val);
    Node* temp=head;
    if(head==NULL){
        new_node=head->val;
    }
    while(temp->next!=NULL){
         
        temp=temp->next;
        temp->next=new_node;
    }
}
int main()
{

    return 0;
}