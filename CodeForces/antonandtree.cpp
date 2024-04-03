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



vector<vector<int>>adj(200001, vector<int>(0));
int max_distance = -1; 
int farthest_node = 0; 
vector<int>col(200001 , -1);
int ans = 0 ;

// 0 -> white
// 1 -> black
void dfs(int src , int par , int dist) {
   if(dist > max_distance ) {
    max_distance = dist ;
    farthest_node = src;
   }

   for(int i = 0 ; i < adj[src].size() ; i++  ) {
    if(adj[src][i] != par) {
        dfs(adj[src][i] , src , dist + int(col[adj[src][i]] != col[src]));
    }
   }
 }
int main() {
    int n ; 
    cin>>n;
    

    for(int i = 1 ; i <= n ; i ++ ) {
        int c;
        cin>> c;
        col[i] = c;
    }

   

  
      


    for(int i = 1 ; i <= n-1 ; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

dfs(1 , 1 , 0);
max_distance = -1;
dfs(farthest_node , farthest_node , 0);
cout<<(max_distance +1) / 2;


   


    




    
}