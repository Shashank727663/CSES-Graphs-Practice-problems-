#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <queue>
using namespace std;

int main() {
    int n ,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    for(int i = 0 ; i < m ;i++) {
        int u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }


    vector<int>indegree(n+1,0);
    queue<int>q;
    for(int i = 1 ; i <= n;i++) {
        for(auto x : adj[i]) {
            indegree[x]++;
        }
    }


    for(int i  = 1 ; i <= n ;i++) {
        if(indegree[i] == 0 ) {
            q.push(i);
        }
    }

    int ans = 0;
    while(!q.empty()) {
        int node  = q.front();
        q.pop();
        for(auto x : adj[node]) {
            if(x == n ) {
                ans++;
            }
            indegree[x]--;

            if(indegree[x] == 0 ) {
                q.push(x);
            }
        }
    }



    cout<<ans<<endl;
}