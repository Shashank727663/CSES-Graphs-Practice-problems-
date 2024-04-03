#include <iostream>
#include <vector>
#include <unordered_map>
#include<math.h>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> repair_days;
unordered_map<int, vector<pair<int, int>>> repair_schedule;

void dfs(int node, int parent, int days, int &current_day) {
    int used = 0;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            used++;
            if (used == days) {
                used = 0;
                current_day++;
            }
            repair_schedule[current_day].push_back({node, neighbor});
            dfs(neighbor, node, days, current_day);
        }
    }
}

int main() {
    int n;
    cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    repair_days.resize(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int max_days = 0;
    for (int i = 1; i <= n; ++i) {
        max_days = max(max_days, static_cast<int>(graph[i].size()));
    }

    cout << max_days << endl;

    int current_day = 1;
    dfs(1, -1, max_days, current_day);

    for (int i = 1; i <= max_days; ++i) {

        for (auto road : repair_schedule[i]) {
           
            cout << road.first << " " << road.second << " ";
            cout<<endl;
            
        }
      
    }

    return 0;
}
