#include <vector>
#include <algorithm>

using namespace std;

class DisJointSet {
public:
    vector<int> parent;
    vector<int> Size;

    DisJointSet(int n) : parent(n), Size(n, 1) {}

    void make(int x) {
        parent[x] = x;
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        // Path compression
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            parent[v] = u;
        }
    }

    void UnionBySize(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (Size[u] < Size[v]) {
                swap(u, v);
            }
            parent[v] = u;
            Size[u] += Size[v];
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisJointSet d(n);
        for (int i = 0; i < n; i++) {
            d.make(i);
        }

        for (auto& x : edges) {
            int u = x[0];
            int v = x[1];
            d.Union(u, v);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (d.find(i) == i) {
                ans++;
            }
        }
        return ans;
    }
};
