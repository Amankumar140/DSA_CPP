#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node *next;
    node(int val){
        this->val=val;
        next=nullptr;
    }
};

class stack{
    public:
    node * top;
    stack(){
        top=nullptr;
    }
   

    void push(int val){
        node * newNode=new node(val);
        newNode->next=top;
        top=newNode;
    }

    int  pop(){
        if(top==nullptr) return -1; 
        node* temp=top;
        int x=top->val;
        top=top->next;
        delete temp;
        return x;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        return top->val;
    }
};

int main(){
    stack s;
    s.push(5);
    s.push(6);
    s.push(16);
    s.push(26);
    s.push(64);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    
}