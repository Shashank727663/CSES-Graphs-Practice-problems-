#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>>dist(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ;j++) {
            cin>>dist[i][j];
        }
        
    }
    
    
    // using floyd warshalls algo for all pair shortest path problems 
    for(int k = 0 ; k < n ;k++) {
        for(int i = 0; i< n ;i++) {
            for(int j = 0 ; j < n;j++) {
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }
    
    
    int q;
    cin>>q;
    while(q--) {
        int s,g,d;
        cin>>s>>g>>d;
        
        int actualdist = dist[s][d];
        int travlled = dist[s][g] + dist[g][d];
        cout<<travlled <<" " <<travlled - actualdist<<endl;
    }
	// your code goes here

}
   