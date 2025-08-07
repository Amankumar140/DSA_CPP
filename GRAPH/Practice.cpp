// graph
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <stack>
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
            if (dfsCycle(adj, i, vis, -1))
                return true;
        }
    }
    return false;
}

// using bfs maintain a parent array if visited and not parent then cycle

// cycle detection of directed graph

bool dfsRec(vector<int> adj[], int s, vector<bool> &vis, vector<bool> &recSt)
{
    vis[s] = true;
    recSt[s] = true;
    for (int x : adj[s])
    {
        if (!vis[x] && dfsRec(adj, x, vis, recSt))
        {
            return true;
        }
        else if (recSt[x])
        {
            return true;
        }
    }
    recSt[s] = false;
    return false;
}

bool dfsCycleDir(vector<int> adj[], int v)
{
    vector<bool> vis(v + 1, false);
    vector<bool> recSt(v + 1, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (dfsRec(adj, i, vis, recSt))
                return true;
        }
    }
    return false;
}

void buildGraphDir(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// print graph

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

// topological sort
vector<int> inDegree(vector<int> adj[], int v)
{
    vector<int> inDeg(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            ++inDeg[x];
        }
    }
    return inDeg;
}

void topologicalSortBfs(vector<int> adj[], int v)
{
    vector<int> inDeg = inDegree(adj, v);
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << endl;
        for (int v : adj[x])
        {
            if (--inDeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
// for cycle detection by kahn's algo use cnt variable and c!=v then return true

// kahn s using dfs

void DFS(vector<int> adj[], int s, vector<bool> &vis, stack<int> &st)
{
    vis[s] = true;
    for (int u : adj[s])
    {
        if (!vis[u])
            DFS(adj, u, vis, st);
    }
    st.push(s);
}

void TopologicalUsingDFS(vector<int> adj[], int v)
{
    vector<bool> vis(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            DFS(adj, i, vis, st);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

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
    // cout << dfsCycleHelp(adj, 1, vertex + 1);

    // directed graph
    int vtx = 6;
    vector<int> adj1[vtx];
    buildGraphDir(adj1, 0, 1);
    buildGraphDir(adj1, 0, 2);
    buildGraphDir(adj1, 1, 3);
    buildGraphDir(adj1, 2, 3);
    // buildGraphDir(adj1, 5, 3);
    buildGraphDir(adj1, 3, 4);
    buildGraphDir(adj1, 3, 5);
    // buildGraphDir(adj1, 5, 2);
    // dfsCycleDir(adj1,vtx+1);
    // cout<<endl;
    // printGraph(adj1,vtx);
    topologicalSortBfs(adj1, vtx);
    cout << endl;
    TopologicalUsingDFS(adj1, vtx);

    return 0;
}