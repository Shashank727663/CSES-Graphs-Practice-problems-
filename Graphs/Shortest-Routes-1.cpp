#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include<climits>
using namespace std;

const int N = 2e5 + 3;
long long int n, m;
vector<vector<pair<long long int, long long int>>> adj(N, vector<pair<long long int, long long int>>());
vector<long long int> dist(N, LLONG_MAX);

void dijkstra() {
    dist[1] = 0;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long int d = pq.top().first;
        long long int v = pq.top().second;
        pq.pop();
         // Skip outdated entry
        if (d > dist[v]) {
            continue;
        }
        for (auto x : adj[v]) {
            long long int nextnode = x.first;
            long long int nextwt = x.second;
            if (dist[nextnode] > nextwt + d) {
                dist[nextnode] = nextwt + d;
                pq.push({dist[nextnode], nextnode});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        long long int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX) {
            cout << "INFINITY ";
        } else {
            cout << dist[i] << " ";
        }
    }

    return 0;
}
