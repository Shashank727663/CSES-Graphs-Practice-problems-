#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include<climits>
#include <queue>
using namespace std;
typedef long long int lli ;

int ans = 0;
vector<int>paths;
vector<vector<pair<int,int>>>adj;
 vector<int>has_policeStation;
 vector<int>vis;


int main() {
    int n , k , d;
    cin >> n >> k >> d;

   set<int>s;
   queue<int>q;
   vis.resize( n*3, 0);
    while(k--) {
        int u;
        cin >> u;
        q.push(u);
        vis[u] = 1;
    }


    adj.resize(n*3);
   
    for(int i = 1 ; i < n ; i ++) {
       
        int u , v ;
        cin >> u >> v;
        adj[u].push_back( { v , i });
        adj[v].push_back({u , i});
        s.insert(i);
      

    }



    while(!q.empty()) {
        auto src = q.front();
        q.pop();
        for(auto x : adj[src]) {
            if(!vis[x.first]) {
                q.push(x.first);
                s.erase(x.second);
               
                cout<<endl;
               
                vis[x.first] = 1;

            }
        }
    }
 


    cout << s.size()<<endl;
    for(auto x :s) {
        cout << x<< " ";
    }


}