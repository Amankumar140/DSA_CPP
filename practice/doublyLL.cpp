#include<iostream>
using namespace std;

class DLL{
    public:
    int val;
    DLL *next;
    DLL *prev;
    DLL(int data){
        val=data;
        next=nullptr;
        prev=nullptr;
    }
};

void insertAtend(DLL *&head, int val){
    DLL * newNode=new DLL(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    DLL * temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
}

void display(DLL *&head){
    DLL * temp= head;
    while (temp!=nullptr)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
       
    }
    cout<<"NULL"<<endl;
    
}

int main()
{
    DLL * head=nullptr;
    insertAtend(head,84);
    insertAtend(head,38);
    insertAtend(head,28);
    insertAtend(head,81);
    display(head);
    return 0;
}