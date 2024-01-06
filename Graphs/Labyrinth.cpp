#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
int dr[4] = { -1,0,1,0};
int dc[4] = { 0 , -1,0,1};
int n , m;
vector<vector<char>>arr(n,vector<char>(m));
vector<vector<bool>>vis(n,vector<bool>(m,false));
void dfs(int x , int y , vector<int>&ans ) {
    vis[x][y] = 1;
    for(int i = 0 ; i < 4 ;i++) {
        int nr = x + dr[i];
        int nc = y + dc[i];
        if(nr >= 0 && nr < n  && nc >= 0 && nc < m && !vis[nr][nc] && arr[nr][nc] != 'B') {
             ans.push_back(1);
            dfs(nr,nc,ans);
           
        }
    }
}
int main() {
    cin>>n>>m;
    vector<int>ans;
    for(int i = 0 ; i  <n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            char c;
        cin>>c;
        arr[i][j] = c;
        if(c == '#') {
            vis[i][j] = true;
        }
        }
    }



}