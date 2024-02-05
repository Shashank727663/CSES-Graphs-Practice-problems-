#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <queue>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int n, m;
int k;
int sx, sy;
vector<vector<char>> adj;
vector<vector<int>> vis;
int max_dist = 0;

void dfs(int x, int y, int dist)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dr[i];
        int nc = y + dc[i];
        if (nx >= 0 && nx < n && nc >= 0 && nc < m)
        {
            if (!vis[nx][nc] && adj[nx][nc] != '*')
            {
                dfs(nx, nc, dist + 1);  // Corrected the recursive call
            }
        }

        if (nx == sx && nc == sy)
        {
            max_dist = max(max_dist, dist + 1);
            if (max_dist >= k)
            {
                return;
            }
        }
    }

    vis[x][y] = 0;
}

int main()
{

    cin >> n >> m;
    cin >> k;
    cin >> sx >> sy;
    adj.resize(n);
    vis.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)  // Corrected the loop condition
        {
            char ch;
            cin >> ch;
            adj[i].push_back(ch);  // Changed to push_back to fill the inner vector
        }
    }

    sx = sx - 1;
    sy = sy - 1;
    max_dist = 0;
    // dfs

    dfs(sx, sy, 0);

    if (max_dist >= k)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
