#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <queue>
using namespace std;
vector<vector<int>> adj;
vector<int> cnt;
vector<int> indegree;
const int modb = 1e9+7;
 int n ,m;
void topo_sort() {
    // topo sort using kahns algo 
    queue<int>q;
    // locking 1.
    for(int i = 2 ; i<=n;i++) {
        if(indegree[i] == 0 ) {
            q.push(i);
        }
    }


    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto x : adj[u]) {
            indegree[x]--;
            if(indegree[x] == 0 ) {
                q.push(x);
            }
        }
    }


    q.push(1);
    cnt[1] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto x : adj[u]) {
            indegree[x]--;
            cnt[x] = cnt[u] + cnt[x];
            cnt[x] %=modb;

            if(indegree[x] == 0 ) {
                q.push(x);
            }
        }
    }



}
int main() {
   
    cin>>n>>m;
    adj.resize(n+1);
    cnt.resize(n+1);
	indegree.resize(n+1);

    for(int i = 0 ; i < m ;i++) {
        int u ,v;
        cin>>u>>v;
        indegree[v]++;
        adj[u].push_back(v);
    }

    topo_sort();
    cout<<cnt[n];

   
}