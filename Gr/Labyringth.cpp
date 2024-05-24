#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int n, m;
vector<vector<bool>> vis(1000, vector<bool>(1000));
vector<vector<char>> arr(1000, vector<char>(1000));
vector<vector<pair<int, int>>> path;


int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int srcx, srcy, destx, desty;

int main() {
    cin >> n >> m;

    // Initialize the 'path' vector with the same size as 'vis'
path.resize(n, vector<pair<int, int>>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'A') {
                srcx = i;
                srcy = j;
            } else if (ch == 'B') {
                destx = i;
                desty = j;
            }

            if (ch == '#') {
                vis[i][j] = true;
            }
            arr[i][j] = ch;
        }
    }

    queue<pair<int, int>> q;
    q.push({srcx, srcy});
    vis[srcx][srcy] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                q.push({nx, ny});
                path[nx][ny] = {dr[i], dc[i]};  
                vis[nx][ny] = true;
            }
        }
    }

    if (!vis[destx][desty]) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    vector<pair<int, int>> ans;
    pair<int, int> end = {destx, desty};

    while (end.first != srcx || end.second != srcy) {
        ans.push_back(path[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto c : ans) {
        if (c.first == 1 && c.second == 0) {
            cout << 'D';
        } else if (c.first == -1 && c.second == 0) {
            cout << 'U';
        } else if (c.first == 0 && c.second == 1) {
            cout << 'R';
        } else if (c.first == 0 && c.second == -1) {
            cout << 'L';
        }
    }

    return 0;
}
