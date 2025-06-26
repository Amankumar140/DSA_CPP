#include <iostream>
using namespace std;
#include <vector>

void adjList(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void adjMat(vector<vector<int>> &mat, int u, int v)
{
    mat[u][v] = 1;
    mat[v][u] = 1;
}

void printMatrixGraph(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        for (int j : mat[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void printAdjList(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void dfsRec(vector<int> adj[], int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (!visited[u])
        {
            dfsRec(adj, u, visited);
        }
    }
}

void dfs(vector<int> adj[], int v, int s)
{
    vector<bool> visited(v + 1, false);
    dfsRec(adj, s, visited);
}

void dfsDisconnected(vector<int> adj[], int v)
{
    vector<bool> visited(v + 1, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfsRec(adj, i, visited);
        }
    }
}

void dfsRecForMat(vector<vector<int>> &mat, int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[s][i] == 1 && !visited[i])
        {
            dfsRecForMat(mat, i, visited);
        }
    }
}

void dfsForMat(vector<vector<int>> &mat, int s = 0)
{
    vector<bool> visited(mat.size(), false);
    dfsRecForMat(mat, s, visited);
}

int main()
{
    int v = 5;
    vector<int> adjListArray[v];
    adjList(adjListArray, 0, 1);
    adjList(adjListArray, 0, 2);
    adjList(adjListArray, 2, 3);
    adjList(adjListArray, 1, 3);
    adjList(adjListArray, 1, 4);
    adjList(adjListArray, 3, 4);
    //  printAdjList(adjListArray, v);
    cout << endl;

    int n = 4;
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));

    adjMat(adjMatrix, 0, 1);
    adjMat(adjMatrix, 0, 2);
    adjMat(adjMatrix, 2, 3);
    adjMat(adjMatrix, 1, 3);
    adjMat(adjMatrix, 1, 4);
    adjMat(adjMatrix, 3, 4);
    printMatrixGraph(adjMatrix);

    dfs(adjListArray, v, 0);
    cout << endl;
    dfsDisconnected(adjListArray, v);
    cout << endl;
    dfsForMat(adjMatrix);

    return 0;
}