#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node *prev;
    node(int data)
    {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

void insertathead(node *&head, int val)
{
    node *new_node = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void insertattail(node*&head, int val){
    node* new_node=new node(val);
    node* temp=head;
    if(head==NULL){
        head=new_node;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void reverseprint(node*head){
    node* temp=head;
    if(head==NULL){
        cout<<"empty"<<endl;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        cout<<temp->val<<"<-";
        temp=temp->prev;
    }
}

int main()
{
    node* ak=NULL;
    insertathead(ak,3);
    insertathead(ak,4);
    insertathead(ak,5);
    insertathead(ak,6);
    insertathead(ak,7);
    insertattail(ak,45);
    insertattail(ak,44);
    insertattail(ak,46);
    insertattail(ak,455);
    insertattail(ak,4555);
    display(ak);
    reverseprint(ak);

    return 0;
}