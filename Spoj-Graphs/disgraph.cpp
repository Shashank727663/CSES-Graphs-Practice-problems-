#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> dis;
vector<int> low;
int timer = 1;
vector<int> vis;
int ans = 0;
void dfs(int node , int parent)
{
    vis[node] = 1;
    dis[node] = low[node] = timer;
    timer++;

    for (auto x : adj[node])
    {
        if(x == parent) {
            continue;
        }

        if(vis[x] == 0) {
            dfs(x,node);
            // node -> x is a bride 
            low[node] = min(low[node] , low[x]);
            if(low[x] > dis[node]) {
                ans++;
            }
        }

        else {
            low[node] = min(low[node] , low[x]);
        }
    }
}




int main() {
    cin>>n;
    adj.resize(n);
    dis.resize(n);
    low.resize(n);
    vis.resize(n,0);

    for(int i = 0 ; i < n ; i ++) {
        
        adj[i].push_back({})
    }
}