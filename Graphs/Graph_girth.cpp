#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent;
vector<int> dist;

int bfs(int n) {
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        dist.assign(n + 1, 1e9); // Reset dist for each component
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto x : adj[node]) {
                if (dist[x] == 1e9) {
                    dist[x] = 1 + dist[node];
                    parent[x] = node;
                    q.push(x);
                } else if (parent[node] != x) { // Removed the redundant condition
                    ans = min(ans, dist[x] + dist[node] + 1);
                }
            }
        }
    }

    if (ans == 1e9) {
        return -1;
    }

    return ans;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    dist.resize(n + 1);

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << bfs(n);

    return 0;
}
