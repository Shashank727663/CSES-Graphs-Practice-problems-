#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;

long long int sv, ev;

// checking for a cycle in the graph using dfs
bool dfs(int src, int p) {
    vis[src] = true;
    parent[src] = p;
    for (auto x : adj[src]) {
        if (x == p) {
            // x is the parent of src, don't go there
            continue;
        }

        if (vis[x]) {
            // if x is visited and not the parent, cycle is found
            sv = x;  // starting vertex to x
            ev = src; // ending vertex to src // src -----> x  ---- > src
            return true;
        }

        if (!vis[x]) {
            if (dfs(x, src) == true) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    parent.resize(n + 1);
    bool cycleFound = false; 

    // adj list construction
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // calling the dfs function
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1) == true) {
                cycleFound = true;
                break; // Break out of the loop once a cycle is found
            }
        }
    }

    if (!cycleFound) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> result;
    int tv = ev;
    result.push_back(ev);
    while (tv != sv) {
        result.push_back(parent[tv]);
        tv = parent[tv];
    }
    result.push_back(ev);

    cout << result.size() << endl;
    for (auto x : result) {
        cout << x << " ";
    }

    return 0;
}
