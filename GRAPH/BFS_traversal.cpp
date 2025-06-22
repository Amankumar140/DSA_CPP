#include <iostream>
using namespace std;
#include <vector>
#include <queue>

void adjancyRep(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " : ";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

// BFS traversal

void BFS(vector<int> adj[], int s, int v)
{
    vector<bool> visited(v + 1, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " " << endl;
        for (int x : adj[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void bfsForDis(vector<int> adj[], int v, int s, vector<bool> &visited)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << endl; // remove for island problem
        for (int x : adj[u])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void bfsDis(vector<int> adj[], int v)
{
    vector<bool> visited(v + 1, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bfsForDis(adj, v, i, visited);
        }
    }
}

int countIsland(vector<int> adj[], int v)
{
    int c = 0;
    vector<bool> visited(v + 1, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bfsForDis(adj, v, i, visited);
            c++;
        }
    }
    return c;
}

int main()
{
    int v = 9;
    vector<int> adj[v];
    adjancyRep(adj, 0, 1);
    adjancyRep(adj, 0, 2);
    adjancyRep(adj, 1, 2);
    adjancyRep(adj, 3, 4);
    adjancyRep(adj, 5, 6);
    adjancyRep(adj, 5, 7);
    adjancyRep(adj, 7, 8);
    printGraph(adj, v);
    cout << endl;
    bfsDis(adj, v);
    cout << "island " << countIsland(adj, v) << endl;

    return 0;
}