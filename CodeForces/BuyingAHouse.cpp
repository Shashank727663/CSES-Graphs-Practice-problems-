
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long int lli;

vector<int> vis;
vector<vector<int>> adj;
vector<int> costs;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    costs.resize(n + 2);

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        costs[i] = c;
    }

    for (int i = 1; i <= n; i++) {
        if (i - 1 >= 1) {
            adj[i].push_back(i - 1);
            adj[i - 1].push_back(i);
        }
        if (i + 1 <= n) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
    }

    int ans = INT_MAX; // Initialize ans with maximum possible value
    queue<int> q;
    q.push(m);
    vis[m] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : adj[node]) {
            if (!vis[x]) {
                vis[x] = 1;
                if (costs[x] != 0 && costs[x] <= k) {
                    ans = min(ans, abs(m - x) * 10); // Update ans with the minimum distance
                }
                q.push(x); // Push the adjacent node to the queue for further exploration
            }
        }
    }

    cout << ans << endl; // Print the minimum distance
    return 0;
}
