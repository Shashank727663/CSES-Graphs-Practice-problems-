#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int n , m;
vector<vector<bool>>vis(1000,vector<bool>(1000));
int dr[] = { -1 , 0 ,1,0};
int dc[] = { 0,-1,0,1};



void dfs(int x ,int y) {
    vis[x][y] = true;
    for(int i = 0 ; i < 4 ;i++) {
        int dx = x + dr[i];
        int dy = y + dc[i];

        if(dx >= 0 && dx < n  &&  dy >= 0 && dy < m && !vis[dx][dy]) {
            dfs(dx,dy);
        }
    }
}
int main() {
    cin>>n>>m;
    vector<vector<char>>arr(n , vector<char>(m));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            char c;
            cin>>c;
            arr[i][j] =c;
            if(c == '#') {
                vis[i][j] = true;
            }

        }
    }

    int ans =  0;
// checking for connected components 
for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ;j++) {
        if(!vis[i][j]) {
            dfs(i,j);
              ans++;
        }
    }
}
    cout<<ans<<endl;

}