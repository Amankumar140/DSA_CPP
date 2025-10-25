#include <iostream>
using namespace std;
#include <vector>
#include <queue>

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void adjacencyMatrix(vector<vector<int>> &list, int u, int v)
{
    list[u][v] = 1;
    list[v][u] = 1;
}

void printGraph(vector<int> adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void printMatrix(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        cout << i << " : ";
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// for adjacency list
void bfsTraversal(vector<int> adj[], int n, int s)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int y : adj[curr])
        {
            if (!visited[y])
            {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

// for adjacency matrix
void bfsTraversal2(vector<vector<int>> &mat, int s)
{
    int n = mat.size();
    vector<bool> visited(n + 1, false);
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int i = 0; i < n; i++)
        {
            if (mat[curr][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// for disconnected graph

// two functions used....
void bfsTraversalMainHelpDisconnected(vector<int> adj[], int n, int s, vector<bool> &visited)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void bfsTraversalMain(vector<int> adj[], int n, int s)
{
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfsTraversalMainHelpDisconnected(adj, n, i, visited);
        }
    }
}

// dfs traversal using recursion

void dfs(vector<int> adj[], int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (int i : adj[s])
    {
        if (!visited[i])
        {
            dfs(adj, i, visited);
        }
    }
}
void dfsMain(vector<int> adj[], int n, int s)
{
    vector<bool> visited(n + 1, false);
    dfs(adj, s, visited);
}

int main()
{
    int n = 4;
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    vector<vector<int>> mat(n, vector<int>(n, 0));
    adjacencyMatrix(mat, 0, 1);
    adjacencyMatrix(mat, 0, 2);
    adjacencyMatrix(mat, 1, 2);
    adjacencyMatrix(mat, 1, 3);
    // printGraph(adj, n);
    // cout << "AdjancyMatrix" << endl;
    // printMatrix(mat);
    // bfsTraversal(adj, n, 0);
    // cout << endl;
    // bfsTraversal2(mat, 0);
    dfsMain(adj,n,0);
    return 0;
}