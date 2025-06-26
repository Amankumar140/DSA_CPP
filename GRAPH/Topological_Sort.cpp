#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

vector<int> InDegree(vector<int> adj[], int V)
{
    vector<int> inDeg(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            ++inDeg[v];
        }
    }
    return inDeg;
}

void TopoLogicalSort_KansAlgo(vector<int> adj[], int V)
{
    vector<int> inDeg = InDegree(adj, V);

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << endl;
        for (int v : adj[u])
        {
            if (--inDeg[v] == 0)
                q.push(v);
        }
    }
}

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

int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    // printGraph(adj, v);

    // InDegree(adj,v);
    TopoLogicalSort_KansAlgo(adj, v);
    return 0;
}