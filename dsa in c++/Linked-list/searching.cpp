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
void insertion(node *&head, int y)
{
    node *new_node = new node(y);
    new_node->next = head;
    head = new_node;
}

void search(node *head, int x){

    node* temp=head;
    int pos=0;
    while(temp->val!=x){
        pos++;
        temp=temp->next;
    }
    cout<<"The position is "<< pos<<endl;
}
void update(node*head,int y,int data){
    node* temp=head;
    int curr_pos=0;
    while(curr_pos!=y){
        temp=temp->next;
        curr_pos++;
    }
    temp->val=data;
}
// deletion of linked-list
void deleteathead(node*&head){
    node* temp=head;
    
}

void display(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* aman=NULL;
    insertion(aman,13);
    insertion(aman,15);
    insertion(aman,16);
    insertion(aman,17);
    insertion(aman,18);
    display(aman);
    search(aman,15);
    update(aman,4,89);
    display(aman);
    

    return 0;
}