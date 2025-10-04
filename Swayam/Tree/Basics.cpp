#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};

int idx = -1;
Node *BuildTree(vector<int> arr)
{
    idx++;
    if (arr[idx] == -1)
    {
        return NULL;
    }
    Node *node = new Node(arr[idx]);
    node->left = BuildTree(arr);
    node->right = BuildTree(arr);
    return node;
}

void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int CountNode(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return CountNode(root->left) + CountNode(root->right) + 1;
}

void levelOrder(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (!curr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << curr->val << "->";
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
}

// height of binary Tree
int heightOfTree(Node *root)
{
    if (!root)
        return -1;
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left, right) + 1;
}

// print all the paths

void printAllPath(Node *root, vector<int> &path)
{
    if (!root)
        return;
    path.push_back(root->val);
    if (!root->left && !root->right)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        printAllPath(root->left, path);
        printAllPath(root->right, path);
    }
    path.pop_back();
}

// get level of the val
int getLevel(Node *root, int val)
{
    if (!root)
        return -1;
    if (root->val == val)
        return 0;
    int x = getLevel(root->left, val);
    if (x != -1)
    {
        return x + 1;
    }
    int y = getLevel(root->right, val);
    if (y != -1)
    {
        return y + 1;
    }
    return -1;
}
// void mirror

void mirror(Node *root)
{
    if (!root)
        return;
    mirror(root->left);
    mirror(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main()
{
    vector<int> arr = {5, 3, 1, -1, -1, 4, -1, -1, 10, 6, -1, 8, -1, -1, 20, -1, -1};
    Node *root = BuildTree(arr);
    // preOrder(root);
    // cout << endl;
    // cout << CountNode(root) << endl;
    levelOrder(root);
    // int path[100];
    //vector<int> path;
    // printAllPath(root, path);
    // cout << heightOfTree(root) << endl;
    mirror(root);
    cout<<"Mirror"<<endl;
    levelOrder(root);

    return 0;
}