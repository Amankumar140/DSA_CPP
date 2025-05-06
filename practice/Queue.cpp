#include<iostream>
using namespace std;

// using arrays
class Queue{
    public:
    int arr[10];
    int front=-1;
    int rear=-1;

    void insert(int val){
        if(rear==9) {
            cout<<"full"<<endl;
            return;
        }
        if(front==-1 && rear==-1){
            front=0;
            arr[++rear]=val;
            return;
        }

        arr[++rear]=val;
    }

    int Delete(){
        if(front==-1) cout<< "Queue is empty"<< endl;
        int x=arr[front++];
        return x;

    }

    bool isEmpty(){
        return front==-1;
    }

    bool isFull(){
        return rear==9;
    }

    int peek(){
        if(isEmpty()) return -1;
        return arr[front];
    }

};

int main()
{
    Queue q;
    q.insert(6);
    q.insert(16);
    q.insert(62);
    cout<<q.peek()<<endl;
    cout<<q.Delete()<<endl;


    return 0;
}