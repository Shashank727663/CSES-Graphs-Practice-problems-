#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int lli;
void dfs(int node , vector<int>&ans,vector<int>&vis,vector<vector<int>>&adj) {
    vis[node] = 1;
    ans.push_back(node);

    for(auto x : adj[node]) {
        if(!vis[x]) {
            dfs(x,ans,vis,adj);
        }else {
            continue;
        }
    }
    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m = (2 * n) - 1;
        vector<vector<int>> adj;

        // Construction of the adj list
        adj.resize(n + 2); // Fix: Resize to n + 2

        // 1st condition.
        for (int i = 1; i <= n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        // 2nd condition adj list construction
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            if (k == 0) {
                adj[i].push_back(n + 1);
            } else if (k == 1) {
                adj[n + 1].push_back(1);
            }
        }

        // dfs traversal
        vector<int> vis(n + 2, 0); // Fix: Resize to n + 2
        vis[1] = 1;
        vector<int> ans;
        
        dfs(1,ans,vis,adj);
       if(ans.size() == n + 1 ) {
        for(auto x : ans) {
            cout<<x<<" ";
        }
       }
       else{
        cout<<-1;
       }
        cout << endl;
    }
    return 0;
}
