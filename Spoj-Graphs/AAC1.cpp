#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli ;


int main() {
 lli t;
    cin>>t;
    while(t--) {
     lli n , m;
        cin>>n>>m;
        vector<lli>adj[n+1];

        // 1) construction adj list 
        while(m--) {
         lli u , v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n+1,-1);
        // -1 => unvisited
        // else marking it with the time when we reach there 

        queue<lli>q;
        q.push(1);
        vis[1] = 0;
        // 1 is the src

        while(!q.empty()) {
         lli node = q.front();
            q.pop();

            if(node == n ) {
                break;
            }
            for(auto x :adj[node]) {
                if(vis[x] == -1) {
                    q.push(x);
                    vis[x] = 1 + vis[node];
                }else{
                    continue;
                }
            }

        }

        cout<<vis[n]<<endl;

    }
}


// another apporoach 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n, m;
        cin >> n >> m;

        vector<lli> adj[n + 1];

        // Construct the adjacency list
        while (m--) {
            lli u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<lli> vis(n + 1, 0);
        vector<lli> dis(n + 1, 1e9);
        queue<pair<lli, lli>> q; // node, dist
        q.push({1, 0});
        vis[1] = 1;
        dis[1] = 0;

        while (!q.empty()) {
            auto node = q.front().first;
            auto time = q.front().second;
            q.pop();

            if (node == n) {
                break;
            }

            for (auto x : adj[node]) {
                if (!vis[x] && dis[x] > time + 1) {
                    vis[x] = 1;
                    dis[x] = time + 1;
                    q.push({x, time + 1});
                }
            }
        }

        cout << dis[n] << endl;
    }

    return 0;
}
