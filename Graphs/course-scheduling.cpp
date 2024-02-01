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
    int n , m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1); 
    for(int i = 0 ; i < m ;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

  

    vector<int>indegree(n+1,0);
    for(int i = 1 ; i <= n ;i++) {
        for(auto x : adj[i]) {
            indegree[x]++;
        }
    }

    queue<int>q;
    for(int i = 1 ; i<= n ;i++) {
        if(indegree[i] == 0 ) {
            q.push(i);
        }
    }
    vector<int>ans;
    int cnt =0;
    while(!q.empty()) {
        int node = q.front();
        ans.push_back(node);
        cnt++;
        q.pop();
        for(auto x : adj[node]) {
            indegree[x]--;
            if(indegree[x] == 0 ) {
                q.push(x);
            }
        }
    }

    if(cnt < n) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }


    for(auto x : ans){
        cout<<x<<" ";
    }
}