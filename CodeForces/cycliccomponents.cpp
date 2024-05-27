#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

vector<vector<int>> adj;
vector<int> vis;
int ans = 0;
bool isCycle = false;


void dfs(int src) {
    vis[src] = 1;
    if(adj[src].size() != 2) {
        isCycle = false;
    }
    for (auto x : adj[src]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
           isCycle = true;
           dfs(i);
           if(isCycle == true) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
