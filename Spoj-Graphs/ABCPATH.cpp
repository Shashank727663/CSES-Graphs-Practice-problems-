#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli ;
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int ans =0;
void dfs(int srcx , int srcy ,int n , int m, vector<vector<char>>&adj  ) {
  for(int i = 0 ; i < 8 ; i ++) {
    int nx  = srcx + dx[i];
    int ny =  srcy + dy[i];
    if( nx >= 0 && nx < n && ny>=0 && ny < m && adj[nx][ny] == adj[srcx][srcy] + 1  ) {
        ans++;
        dfs(nx , ny , n , m , adj);
    }
    }
    
}
int main () {
    int n , m;
  
    vector<vector<char>>adj(  55 , vector<char>(55));
   while(true) {
    cin >> n >> m;
    if( n == 0 && m ==0) {
        break;
    }


    for(int i =  0 ; i < n ; i ++) {
        for(int j = 0 ; j < m  ;  j++ ) {
            cin >> adj[i][j];
        }
    }

   }


   int srcx , srcy;
   for(int i = 0 ; i < 55 ; i ++) {
    for(int j = 0 ; j < 55 ; i ++) {
        if(adj[i][j] == 'A' ) {
            srcx = i;
            srcy = j;
        }
    }
   }



   dfs( srcx , srcy , n , m , adj);
   cout<< ans << endl;
   



}
