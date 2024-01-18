#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include<iostream>
using namespace std;
int n,m;
vector<vector<int>>adj;
vector<int>color;
vector<bool>vis;

bool dfs(int u , int col,int parent) {
    vis[u] = 1;
    color[u] = col;

    for(auto x : adj[u]) {
        if(u == parent) {
            continue;
        }

        if(color[x] == 0 ) {
            if(!dfs(x,(color[u] ^ 3),u)) {
                return false;
            }
        }

        if(color[x] == color[u]) {
            return false;
        }
    }
    return true;

}

bool color_all() {
    for(int i = 0 ;i <=n ; i++) {
        if(!vis[i]) {
            if(!dfs(i,1,-1)) {
                return false;
            }
        }
    }

    return true;
}
int main() {
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    color.resize(n+1);
    vis.resize(n+1);

    while(m--) {
        int u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = color_all();
    if(!ans) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }


    for(int i = 1 ;i <=n;i++) {
        cout<<color[i]<<" ";
    }

}