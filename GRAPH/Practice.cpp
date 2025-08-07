// graph
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
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

// dfs traversal

void dfs(vector<int> adj[], int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (!visited[u])
        {
            dfs(adj, u, visited);
        }
    }
}

void dfsHelp(vector<int> adj[], int s, int v)
{
    vector<bool> visited(v + 1, false);
    dfs(adj, s, visited);
}

// shortest path of the
void shortestPath(vector<int> adj[], int s, int v, vector<int> &dis)
{
    vector<bool> vis(v + 1, false);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int u : adj[curr])
        {
            if (!vis[u])
            {
                q.push(u);
                dis[u] = dis[curr] + 1;
                vis[u] = true;
            }
        }
    }
}

// cycle detection using dfs

bool dfsCycle(vector<int> adj[], int s, vector<bool> &visited, int parent)
{
    visited[s] = true;
    for (int u : adj[s])
    {
        if (!visited[u])
        {
            if (dfsCycle(adj, u, visited, s))
                return true;
            else if (parent != u)
                return true;
        }
    }
    return false;
}

bool dfsCycleHelp(vector<int> adj[], int s, int v)
{
    vector<bool> vis(v + 1, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (dfsCycle(adj, s, vis, -1))
                return true;
        }
    }
    return false;
}

// using bfs maintain a parent array if visited and not parent then cycle

int main()
{
    int vertex = 5;
    vector<int> adj[vertex + 1];
    buildGraph(adj, 1, 4);
    buildGraph(adj, 1, 2);
    buildGraph(adj, 4, 5);
    buildGraph(adj, 5, 2);
    buildGraph(adj, 2, 3);
    buildGraph(adj, 5, 3);

    // BFS(adj, 1, vertex);
    // cout << endl;
    // bfsDisconnected(adj, 2, vertex);
    // cout<<"\nDFS"<<endl;
    // dfsHelp(adj,1,vertex);

    // for shortest path
    vector<int> dis(vertex + 1, INT_MAX);
    shortestPath(adj, 1, vertex + 1, dis);
    // for(int i=1;i<=vertex; i++){
    //     cout<<dis[i]<<endl;
    // }

    cout<<dfsCycleHelp(adj, 1, vertex + 1);

    return 0;
}