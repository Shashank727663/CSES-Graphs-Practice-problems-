#include<bits/stdc++.h>

using namespace std; 
typedef long long int ll; 


vector<vector<ll>> adj;
vector<ll>vis; 
vector<ll>ans; 

ll dfs(ll src) { 
    ll res = 0;
    vis[src] = 1;
    for(auto x : adj[src]) { 
        if(!vis[x]) { 
            res += dfs(x);
        }
    }
    return ans[src] = res + 1; 
}
int main() { 
      ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    cin >> n; 
     adj.assign(n, vector<ll>());
    vis.assign(n,false);
    ans.assign(n,0);

    for(int i = 1 ;  i < n ;i++) { 
        int boss; 
        cin >> boss; 
        boss--;
        adj[boss].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] - 1 << " ";
    }
    return 0; 
}