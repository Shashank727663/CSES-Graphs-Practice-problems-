#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include<climits>
#include <queue>
using namespace std;
typedef long long int lli ;

class DisJointSet
{
public:
    vector<int> parent;
    vector<int> Size;

    DisJointSet(int n) : parent(n), Size(n, 1) {}

    void make(int x)
    {
        parent[x] = x;
    }

    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        // Path compression
        return parent[x] = find(parent[x]);
    }

    bool Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            parent[v] = u;
            return false; // No cycle detected
        }
        return true; // Cycle detected
    }

    void UnionBySize(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (Size[u] < Size[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            Size[u] += Size[v];
        }
    }

    bool hasCycle(const vector<vector<int>> &graph)
    {
        int n = graph.size();
        DisJointSet ds(n);

        for (int u = 0; u < n; ++u)
        {
            for (int v : graph[u])
            {
                if (ds.Union(u, v))
                    return true; // Cycle detected
            }
        }

        return false; // No cycle detected
    }
};






int main() {
    int n , m1 ,m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> mocha(m1);
    vector<vector<int>> diana(m2);
    DisJointSet mo(n+1);
    DisJointSet di(n+1);

    for(int i =1  ; i <= n ; i++){
        mo.make(i);
        di.make(i);
    }


    for(int i  = 0 ; i < m1 ; i++) {
        int u , v;
        cin >> u >> v;
        mocha[u].push_back(v);
        mo.Union(u,v);
    }

    for(int i = 0 ; i < m2 ;i++) {
        int u , v;
        cin>> u >> v;
        diana[u].push_back(v);
        di.Union( u ,v);
    }




}
