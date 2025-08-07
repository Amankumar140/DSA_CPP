// graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void buildGraph(vector<int> adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> adj[], int s, int v)
{
    vector<bool> vis(v + 1, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int u : adj[x])
        {
            if (!vis[u])
            {
                q.push(u);
                vis[u] = true;
            }
        }
    }
}

// for disconnected graph there is two functions

void bfsDis(vector<int> adj[], int s, int v, vector<bool> &visited)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int u : adj[curr])
        {
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

void bfsDisconnected(vector<int> adj[], int s, int v)
{
    vector<bool> visited(v + 1, false);
    visited[s] = true;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bfsDis(adj, s, v, visited);
        }
    }
}

int main()
{
    int vertex = 6;
    vector<int> adj[vertex];
    buildGraph(adj, 1, 4);
    buildGraph(adj, 1, 2);
    buildGraph(adj, 4, 5);
    buildGraph(adj, 5, 2);
    buildGraph(adj, 2, 3);
    buildGraph(adj, 5, 3);

    BFS(adj, 1, vertex);
    cout << endl;
    bfsDisconnected(adj, 2, vertex);

    return 0;
}