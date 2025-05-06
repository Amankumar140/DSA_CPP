#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node *next;
    node(int data){
        val=data;
        next=nullptr;
    }
};


class Queue{
    public:

    node * front;
    node * rear;
    Queue(){
        front=nullptr;
        rear=nullptr;
    }

    void push(int val){
        node * newNode=new node(val);
        if(front ==nullptr && rear==nullptr){
            front=newNode;
            rear=newNode;
            return;
        }
         
        rear->next=newNode;
        rear=newNode;


    }
     
     int Delete(){
        if( isEmpty()) return-1;

        node * temp=front;
        int remove=temp->val;
        front=front->next;
        delete temp;
        return remove;
     }

     bool isEmpty(){
        return front==nullptr;
     }

     int peek(){
        if(isEmpty()) return -1;
        return front->val;
     }

};

int main()
{
    Queue q;
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(43);
    cout<<q.peek()<<endl;
    cout<<q.Delete()<<endl;
    
    return 0;
}