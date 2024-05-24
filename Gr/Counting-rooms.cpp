#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
int dr[] = { -1 , 0 ,1,0};
int dc[] = { 0,-1,0,1};
int n , m;
vector<vector<bool>>vis(1000 , vector<bool>(1000));
void dfs(int x , int y ) {
    vis[x][y] = true;
    for(int i = 0 ; i < 4 ; i++) {
        int di  = x + dr[i];
        int dj = y + dc[i];
        if(di >=0 && di <n && dj >= 0 && dj< m && !vis[di][dj]) {
            dfs(di,dj);
        }
    }
}



int main() {
    cin >> n >> m ;
    vector<vector<char>>adj( n , vector<char>(m));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            char c;
            cin >> c;
            adj[i][j] = c;
            if(adj[i][j] == '#') {
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(!vis[i][j]) {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<< ans << endl;

}