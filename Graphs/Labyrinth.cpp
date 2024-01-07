#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> arr(1000, vector<char>(1000));
vector<vector<bool>> vis(1000, vector<bool>(1000, false));
vector<vector<pair<int, int>>> path;  // vector of vectors of pairs
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int srcx, srcy, destx, desty;

int main() {
    queue<pair<int, int>> q;
    cin >> n >> m;
    path.resize(n, vector<pair<int, int>>(m));  // Resize each inner vector

    for (int i = 0; i < n; i++) {
        vis[i].resize(m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c;
            if (c == '#') {
                vis[i][j] = true;
            } else if (c == 'A') {
                srcx = i;
                srcy = j;
            } else if (c == 'B') {
                destx = i;
                desty = j;
            }
        }
    }

    q.push({srcx, srcy});
    vis[srcx][srcy] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                q.push({nr, nc});
                path[nr][nc] = {dr[i], dc[i]};
                vis[nr][nc] = true;
            }
        }
    }

    if (!vis[destx][desty]) {
        cout << "NO" << endl;
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
