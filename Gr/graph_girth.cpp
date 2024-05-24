#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli;

lli n , m;
vector<vector<int>>adj;
vector<int>dist;
vector<int>parent;
int bfs(lli n ) {
    int ans  = 1e9;
    for(int i = 1 ; i<= n ;i++) {
        dist.assign(n+1 , 1e9);
        dist[i] = 0;
        queue<lli>q;
        q.push(i);
        while(!q.empty()) {
            lli node = q.front();
            q.pop();
            for(auto x : adj[node]) {
                if(dist[x] == 1e9) {
                    dist[x] = 1 + dist[node];
                    parent[x] = node;
                    q.push(x);
                }else if(parent[node] != x) {
                    ans = min(ans , dist[x] + dist[node] + 1);
                }
            }
        }


    }


    if(ans == 1e9) {
        return -1;
    }


    return ans;
}
int main() {
    cin >> n >> m;
    adj.resize(n+1);
    dist.resize(n+1);
    parent.resize(n+1,-1);

    while(m--) {
        int u , v;
        cin >> u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << bfs(n)<<endl;


}