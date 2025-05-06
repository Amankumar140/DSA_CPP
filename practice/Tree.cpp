#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node * left;
    node * right;
    node(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }

};


void preorder(node * root){
    if(root==nullptr) return;
    cout<<root->val<<endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->val<< endl;
    inorder(root->right);
}
void postorder(node *root){
    if(root==nullptr) return;
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->val<<endl;
}


int main()
{
    node * root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    preorder(root);
    cout<<" "<<endl;
    postorder(root);
    cout<<" "<<endl;
    inorder(root);





    return 0;
}