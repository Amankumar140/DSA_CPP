#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1,Node*back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
int lengthofll(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp ->next != nullptr){
        temp = temp->next;
        cnt++;
    }
    return cnt;

}
void search(int n,Node* head){
    Node* temp = head;
    
     while (temp != nullptr) {
        if (temp->data == n) {
            cout << "FOUND" << endl;
            return; // stop searching
        }
        temp = temp->next;
    }
    cout << "NOT FOUND" << endl;
}
int main(){
    int arr[]= {2,4,6,8,10};
    Node* y = new Node(arr[0]);
    Node* ptr  = y;
    for(int i = 1;i<=5;i++){
        Node* temp = new Node(arr[i],nullptr,ptr);
        ptr->next = temp;
      
        ptr = temp;
    }
    ptr = y;
    while(ptr->next!= nullptr){
        cout<<ptr->data<<" ";
        ptr = ptr-> next;
    }
    int n = lengthofll(y);
    cout<<n<<endl;
    search(4,y);
}