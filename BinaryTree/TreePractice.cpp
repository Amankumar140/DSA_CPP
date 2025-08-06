#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(vector<int> preorder, int &idx)
{
    idx++;
    if (preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);
    return root;
}

void printPreorder(Node *root)
{
    if (root == NULL)
    {
        cout << "NULL ";
        return;
    }
    cout << root->key << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();
        // line wise print
        if (x == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
                ;
            }
            else
            {
                break;
            }
        }
        cout << x->key << " ";
        if (x->left)
            q.push(x->left);
        if (x->right)
            q.push(x->right);
    }
}

// print k distance node

void printKDis(Node *root, int dis, int k)
{
    if (root == NULL)
        return;
    if (dis == k)
    {
        cout << root->key << " ";
    }
    printKDis(root->left, dis + 1, k);
    printKDis(root->right, dis + 1, k);
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

int sizeOfBT(Node *root)
{
    if (root == NULL)
        return 0;
    //     int left = sizeOfBT(root->left) ;
    //     int right = sizeOfBT(root->left) ;
    //     return left + right+1;

    // iterative

    queue<Node *> q;
    q.push(root);
    int c = 0;
    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();
        c++;
        if (x->left)
            q.push(x->left);
        if (x->right)
            q.push(x->right);
    }
    return c;
}

// recursive sol of the left view
// int maxlevel = 0;

void leftviewRec(Node *root, int level, int &maxlevel)
{
    if (root == NULL)
        return;
    if (level > maxlevel)
    {
        cout << root->key << " ";
        maxlevel = level;
    }
    leftviewRec(root->left, level + 1, maxlevel);
    leftviewRec(root->right, level + 1, maxlevel);
};
// exact the iterative sol of level order

void leftViewIter(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;

    q.push(root);
    while (!q.empty())
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

// children sum property

bool ChildSumProp(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (!root->left && !root->right)
    {
        return true;
    }
    int sum = 0;
    if (root->left)
        sum += root->left->key;
    if (root->right)
        sum += root->right->key;

    return (root->key == sum && ChildSumProp(root->left) && ChildSumProp(root->right));
}

// is balanced tree or not

// the lHeight- RHeight <=1 then tree is balanced

// this take O(n^2) b/c two time rec
// bool isBalanced(Node* root){
//     if(!root) return true;
//     int lH=height(root->left);
//     int rH=height(root->right);
//     return (abs(lH-rH)<=1 && isBalanced(root->left) && isBalanced(root->right));
// }

// optimal approach of isBalanced

int isBalanced(Node *root)
{
    if (!root)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(rh, lh) + 1;
}

int width(Node *root)
{
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {

        int count = q.size();
        res = max(count, res);
        for (int i = 0; i < count; i++)
        {
            Node *x = q.front();
            q.pop();
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
    }
    return res;
}

int main()
{
    int idx = -1;
    vector<int> preorder1 = {1, 2, 3, -1, -1, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1};
    Node *root1 = buildTree(preorder1, idx);
    // printPreorder(root);
    // levelOrder(root);
    // cout << height(root) << endl;
    // printKDis(root, 0,2);
    // cout << sizeOfBT(root) << endl;
    int maxlevel = 0;
    // leftviewRec(root, 1, maxlevel);
    // leftViewIter(root);
    int index=-1;
    vector<int> preorder = {20, 8, 3, -1, -1, 5, -1, -1, 12, -1, -1};
    Node *root = buildTree(preorder, index);
    //cout << (ChildSumProp(root) ? "True" : "False") << endl;
    cout<<width(root1)<<endl;
    cout<<width(root)<<endl;

    return 0;
}