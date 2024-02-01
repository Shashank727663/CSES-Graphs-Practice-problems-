#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef long long int lli;

lli n, m;
vector<vector<pair<lli, lli>>> adj;
vector<lli> parent;
vector<bool> vis;
vector<lli> dist;

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    vis.resize(n + 1, 0);
    dist.resize(n + 1, LLONG_MAX);

    // Using set as a priority queue
    set<pair<lli, lli>> pq;
    
    // Adjacency list construction
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, -1);
    }

    pq.insert({0, 1});
    dist[1] = 0;
    parent[1] = 0;
    vis[1] = true;

    while (!pq.empty()) {
        auto it = pq.begin();
        auto wt = it->first;
        auto node = it->second;
        pq.erase(it);

        if (wt > dist[node]) {
            continue;
        }

        for (auto x : adj[node]) {
            lli nextnode = x.first;
            lli d = x.second;

            if (dist[nextnode] > wt + d) {
                dist[nextnode] = wt + d;
                parent[nextnode] = node;
                pq.insert({dist[nextnode], nextnode});
            }
        }
    }

    vector<int> ans;
    if (dist[n] == LLONG_MAX) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    auto curr = n;
    while (parent[curr] != 0) {
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(1);

    cout << ans.size() << '\n';

    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}
