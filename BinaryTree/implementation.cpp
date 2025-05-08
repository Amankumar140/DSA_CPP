#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preorder)
{

    idx++;
    if (preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "-> ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << "-> ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "-> ";
}

void levelOrder(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);
    while (Q.size() > 0)
    {
        Node *curr = Q.front();
        Q.pop();

        // only for lineWise
        if (curr == NULL)
        {
            if (!Q.empty())
            {
                cout << endl;
                Q.push(NULL);
                continue;
                ;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << "-> ";
        if (curr->left != NULL)
            Q.push(curr->left);
        if (curr->right != NULL)
            Q.push(curr->right);
    }
    cout << endl;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int count(Node *root)
{
    if (root == NULL)
        return 0;
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}

int sum(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

// TC O(nlogn)
void topView(Node *root)
{
    queue<pair<Node *, int>> q; // {Node, horizontal distance}
    map<int, int> m;            // {HD, val}
    q.push({root, 0});
    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if (m.find(currHD) == m.end())
        {
            m[currHD] = curr->data;
        }

        if (curr->left != NULL)
            q.push({curr->left, currHD - 1});
        if (curr->right != NULL)
            q.push({curr->right, currHD + 1});
    }

    for (auto it : m)
    {
        cout << it.second << " ";
    }
    cout << endl;
}

// kth level
void kLevel(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    kLevel(root->left, k - 1);
    kLevel(root->right, k - 1);
}

int main()
{
    vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    Node *tree = buildTree(preorder);
    preOrder(tree);
    //  cout<<endl;
    //  inOrder(tree);
    //  cout<<endl;
    //  postOrder(tree);
    //  cout<<endl;
    //  levelOrder(tree);
    // cout << height(tree) << endl;
    // cout << count(tree) << endl;
    // cout << sum(tree) << endl;

    // topView(tree);
    kLevel(tree, 2);
    cout << endl;

    return 0;
}