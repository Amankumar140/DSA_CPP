#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back({v, wt});
}

void topoSortDFS(int v, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st) {
    vis[v] = true;
    for (auto it : adj[v]) {
        int v = it.first;
        if (!vis[v])
            topoSortDFS(v, adj, vis, st);
    }
    st.push(v);
}

vector<int> shortestPathInDAG(int V, vector<pair<int, int>> adj[], int s) {
    vector<bool> vis(V, false);
    stack<int> st;

    // 1. Topological Sort
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            topoSortDFS(i, adj, vis, st);
    }

    // 2. Initialize distances
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;

    // 3. Process vertices in topological order
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (dist[u] != INT_MAX) {
            for (auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    return dist;
}

int main() {
    int V = 6;
    vector<pair<int, int>> adj[V];

    // from image
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 5, 3, 1);

    int src = 0;
    vector<int> dist = shortestPathInDAG(V, adj, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
