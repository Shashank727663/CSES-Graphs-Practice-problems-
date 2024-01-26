#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int ll;
ll n, m;
vector<vector<pair<ll, ll>>> adj; // Change the type to pair<ll, ll>
vector<ll> dist;

void bellman_ford() {
    // n - 1 relaxations
    for (ll i = 1; i < n; i++) {
        for (ll u = 1; u <= n; u++) {
            for (auto& edge : adj[u]) {
                ll v = edge.first;
                ll w = edge.second;

                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }

                dist[v] = max(static_cast<ll>(1e8 * -1), dist[v]);

            }
        }
    }

    // nth relaxation check for a negavtive weight cycle
    for (ll u = 1; u <= n; u++) {
        for (auto& edge : adj[u]) {
            ll v = edge.first;
            ll w = edge.second;
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                dist[v] = 1e8 * (-1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dist.resize(n + 1, 1e8);
    adj.resize(n + 1);

    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, (w * -1)});
    }

    dist[1] = 0;
    bellman_ford();

    if (dist[n] == 1e8 * (-1)) {
        cout << -1 << endl;
        return 0;
    }

    cout << dist[n] * -1 << endl;

    return 0;
}
