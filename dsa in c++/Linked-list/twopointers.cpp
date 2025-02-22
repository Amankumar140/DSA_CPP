// #include<iostream>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* next;
//     node(int data){
//         val=data;
//         next=NULL;
//     }

// }; 

// void insertatHead(node*&head,int val){
//     node* new_node=new node(val);
//     node*temp=head;
//     if(head==NULL){
//         head=new_node;
//         return;

//     }
//     while(temp->next!=NULL){
//         temp= temp->next;
//     }
//     temp->next=new_node;
// }

// void display(node * head){
//     node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->val<<"-> ";
//         temp=temp->next;
//     }
//     cout<<"NULL"<<endl;
// }


// bool equal(node* head1, node*head2 ){
//     node* temp=head1;
//     node* temp2=head2;

//     while(temp!=NULL && temp2!=NULL){
//         if(temp->val!=temp2->val){
//             return false;
//         }
//         temp=temp->next;
//         temp2=temp2->next;
//     }
//     return(temp==NULL&& temp2==NULL);

// }

// void intersection( node *head1,node *head2){
    
// }

// int main()
// {
//     node * aman=NULL;
//     insertatHead(aman,4);
//     insertatHead(aman,9);
//     insertatHead(aman,8);
//     insertatHead(aman,7);
//     insertatHead(aman,6);
//     insertatHead(aman,5);
//     node* akhil=NULL;
//     insertatHead(akhil,4);
//     insertatHead(akhil,9);
//     insertatHead(akhil,8);
//     insertatHead(akhil,7);
//     insertatHead(akhil,6);
//     insertatHead(akhil,5);
//     cout<<equal(aman,akhil)<<endl;
//     display(aman);
//     display(akhil);



//     return 0;
// }




// intersection of nodes....

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    }

}; 

void insertatHead(node*&head,int val){
    node* new_node=new node(val);
    node*temp=head;
    if(head==NULL){
        head=new_node;
        return;

    }
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next=new_node;
}

void display(node * head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int length(node*head){
    int length=0;
    node*temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}
node* moveheadby(node* head,int k){
    node*ptr=head;
    while(k--){
        ptr=ptr->next;
    }
    return ptr;
}

node* intersection( node *head1,node *head2){
    node* ptr1;
    node *ptr2;
     
    int l1=length(head1);
    int l2=length(head2);
    if(l1>l2){
        int k=l1-l2;
        ptr1=moveheadby(head1,k);
        ptr2=head2;
    }
    else{
        int k=l2-l1;
        ptr1=head1;
        ptr2=moveheadby(head2,k);
    }
    while(ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
}

void remove(node* &head,int k){
    node*ptr1=head;
    node*ptr2=head;
    int count=k;
    while(count--){
        ptr2=ptr2->next;
    }
    if(ptr2==NULL){
        node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}

int main()
{
    node * aman=NULL;
    insertatHead(aman,4);
    insertatHead(aman,7);
    insertatHead(aman,8);
    insertatHead(aman,7);
    insertatHead(aman,6);
    insertatHead(aman,5);
    node* akhil=NULL;
    insertatHead(akhil,4);
    insertatHead(akhil,9);
    insertatHead(akhil,8);
     
    display(aman);
    remove(aman,3);
    display(aman);
    display(akhil);
    remove(akhil,2);
    display(akhil);
     



    return 0;
}