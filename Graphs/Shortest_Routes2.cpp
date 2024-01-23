#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int ll;
int main() {
ll n , m ,q;
    cin>>n>>m>>q;
    vector<vector<ll>>edges;
    for(int i = 0 ; i < m ; i++) {
   ll u,v,w;
       cin>>u>>v>>w;
       edges.push_back({u,v,w});
    }

    vector<vector<ll>> adj(n+1 , vector<ll>(n+1,1e17));
    for(ll i = 1 ; i <= n ; i++ ) {
        for(ll j = 1 ; j <=n ;j++) {
            if( i == j ) {
                adj[i][j] = 0;
            }
        }
    }


    for(auto x : edges) {
        auto ut = x[0];
        auto vt = x[1];
        auto wt = x[2];
        adj[ut][vt] = min(wt, adj[ut][vt]);
        adj[vt][ut] = min(wt,adj[ut][vt]);
    }
    // minimizing all pairs here 

    for(ll i = 1 ;i <= n ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            for(ll k = 1 ; k<= n ;k++) {
                adj[j][k] = min(adj[j][k] ,adj[j][i] + adj[i][k] );
            }
        }
    }


while(q--) {
		int a, b;
		cin >> a >> b;
		if(adj[a][b] == 1e17)
			cout << -1 << '\n';
		else
		cout << adj[a][b] << '\n';
	}
	return 0;

}