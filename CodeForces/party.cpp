#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli;
vector<vector<int>>adj;
vector<int>vis;

int main() {
    int n;
    cin >> n;
    adj.resize(n+1);
    vis.resize(n+1,0);

    for(int i = 1 ; i<= n ; i++) {
        int x;
        cin>>x;
        if(x != -1) {
            adj[x].push_back(i);
        }else {
            adj[0].push_back(i);
        }
    }


    queue<pair<int,int>>q;
    q.push({0,1});
    vis[0]=1;
    // node ,lvl;
    int ans = -1;
    while(!q.empty()) {
        int node = q.front().first;
        int lvl = q.front().second;

        q.pop();
        for(auto x : adj[node]) {
           if(!vis[x]) {
            vis[x] = 1;
            q.push({x, lvl + 1});
           }

        }
         ans =  max(ans , lvl);


      
    }

    cout << ans - 1 << endl;


}