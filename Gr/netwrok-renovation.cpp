#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli;
int n ;
const int maxi=1e5 + 1;
vector<int>adj[maxi];
vector<int>leaves;
void dfs(int src ,int par) {
    if((int)adj[src].size() == 1) {
        // leaf node check
        leaves.push_back(src);
    }

    for(auto x: adj[src]) {
        if(x != par) {
            dfs(x , src);
        }
    }
}
int main() {
    cin >> n;
   for(int i = 0 ; i < n-1 ; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1,-1);
   int  ans = (int) leaves.size();
   cout << (ans+1) / 2<<endl;

   for(int i=0;i<(ans + 1) / 2 ;i++) {
    cout << leaves[i] <<" ";
    cout<< leaves[i + ans / 2]<<endl;
   }

}