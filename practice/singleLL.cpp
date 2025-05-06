#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
         data=val;
        next=nullptr;
    }
};

void intialiseAtBeg(node *& head, int val){
    node* newNode=new node(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}

void display(node *head){
    node * temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    
}

void reverse(node*&head){
    if(head==nullptr){
        return;
    }
    node * prev=nullptr;
    node *curr=head;
    node *next=nullptr;
    while (curr!=nullptr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    head=prev;
}

int main()
{
    node* head=nullptr;
    intialiseAtBeg(head,4);
    intialiseAtBeg(head,5);
    intialiseAtBeg(head,25);
    intialiseAtBeg(head,53);
    intialiseAtBeg(head,56);
    display(head);
    reverse(head);

    display(head);
    return 0;
}