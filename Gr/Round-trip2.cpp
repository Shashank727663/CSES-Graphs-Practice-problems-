#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> parent;
int start, finish;

bool dfs(int src, int par, vector<bool> &recStack) {
    vis[src] = 1;
    recStack[src] = true;

    for (auto x : adj[src]) {
        if (!vis[x]) {
            parent[x] = src;
            if (dfs(x, src, recStack)) {
                return true;
            }
        } else if (recStack[x]) {
            finish = src;
            start = x;
            return true;
        }
    }

    recStack[src] = false;
    return false;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> recStack(n + 1, false);
    start = -1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, recStack)) {
                break;
            }
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = finish; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
