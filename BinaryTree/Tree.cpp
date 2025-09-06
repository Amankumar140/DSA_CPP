#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int idx = -1;
Node *BuildTree(int preorder[], int n)
{
    idx++;
    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = BuildTree(preorder, n);
    root->right = BuildTree(preorder, n);
    return root;
}

void printTree(Node *root)
{
    if (!root)
    {
        cout << "NULL-> ";
        return;
    }
    cout << root->data << "-> ";
    printTree(root->left);
    printTree(root->right);
}

int heightTree(Node *root)
{
    if (!root)
        return 0;
    int left = heightTree(root->left);
    int right = heightTree(root->right);
    return max(left, right) + 1;
}

void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (!curr)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}



int main()
{

    int arr[] = {1, 2, 4, 8, -1, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = BuildTree(arr, n);
    // printTree(root);
    // cout << endl;
    // cout << heightTree(root) << endl;
    levelOrder(root);

    return 0;
}
