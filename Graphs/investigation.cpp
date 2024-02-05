#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long int
#define endl "\n"
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

int n, m;
const int INF = 1e17;
const int modb = 1e9+7;
const int MAXN = 1e5+1;
vector<vector<pair<int,int>>> g(MAXN);
vector<int> cost(MAXN);
vector<int> route(MAXN);
vector<int> min_f(MAXN);
vector<int> max_f(MAXN);
void dij()
{
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({0,1});
	cost[1] = 0;
	route[1] = 1;
	while(!pq.empty())
	{
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(d > cost[u]) continue;
		for(auto e: g[u])
		{
			int v = e.first;
			int c = e.second;
			if(c+d > cost[v]) continue;
			if(c+d == cost[v]) 
			{
				route[v] += route[u];
				route[v] %= modb;
				min_f[v] = min(min_f[u]+1, min_f[v]);
				max_f[v] = max(max_f[u]+1, max_f[v]);
			}
			if(c+d < cost[v])
			{
				cost[v] = c+d;
				route[v] = route[u];
				min_f[v] = min_f[u]+1;
				max_f[v] = max_f[u]+1;
				pq.push({cost[v],v});
			}
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i <m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	for(int i = 2; i <= n; ++i)
	{
		cost[i] = INF;
	}
	dij();
	cout << cost[n] <<" " <<route[n] <<" "<<min_f[n] <<" "<<max_f[n] << endl;
}