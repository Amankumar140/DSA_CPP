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

class linkedlist
{
    public : node *head;
    linkedlist(){
        head=NULL;
    }
     void insertattail(int val){
        node* new_node=new node(val);
        
        if(head==NULL){
            head=new_node;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
     }
     void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
     }

};

void deletealternatenodes(node*&head){
    node* curr_node=head;
    while(curr_node!=NULL && curr_node->next!=NULL){
        node* temp=curr_node->next;
        curr_node->next=curr_node->next->next;
        free(temp);
        curr_node=curr_node->next;

    }
}

int main()
{
     linkedlist aman;
     aman.insertattail(4);
     aman.insertattail(5);
     aman.insertattail(6);
     aman.insertattail(7);
     aman.insertattail(9);
     aman.insertattail(81);
     aman.insertattail(19);
     aman.insertattail(28);
     aman.display();
     deletealternatenodes(aman.head);
     aman.display();
    return 0;
}