#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
vector<vector<int>> adj(200005);
vector<bool>vis(200005);
int dp[200005][2];
 int ans = 0 ;

void dfs(int prev ,int curr) {
   
    for(auto x : adj[curr] ) {
        if(x != prev) {
            dfs(curr  , x);
            if(!vis[x] && !vis[curr]) {
                vis[x] = vis[curr] = 1;
            }
            ans++;
        }
    }
}
int main(){
    int n;
    cin>>n;

    for(int i = 0 ; i < n-1;i++) {
        int u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,1);
    cout<<ans<<endl;


}