#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> roads;
int cc = 0;

void dfs(int src) {
    vis[src] = true;
    for (auto x : adj[src]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
}

void Connected_Components() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cc++;
            roads.push_back(i);
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    vis.resize(n + 1);
    adj.resize(n + 1);

    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Connected_Components();
    cout << cc - 1 << endl;
    if (cc > 1) {
        int u = roads[0];
        int v;
        for (int i = 1; i < cc; i++) {
            v = roads[i];
            cout << u << " " << v << endl;
            u = v;
        }
    }

    return 0;
}
