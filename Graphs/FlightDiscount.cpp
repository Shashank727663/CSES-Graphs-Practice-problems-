 #include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int INF = 9e17; 
long long int n, m;
vector<vector<pair<long long int,long long int>>> g;
vector<long long int> dist; 
vector<int> disc;
 
void dijkstra()
{
	priority_queue< 
	pair<long long int , pair<long long int ,long long int >>, 
	vector<pair<long long int , pair<long long int ,long long int >>>,
	greater<pair<long long int , pair<long long int ,long long int >>>
	> pq;
	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF; 
		disc[i] = INF;
	}
	pq.push({0,{1,0}});
 
	while(!pq.empty())
	{
		auto d = pq.top().first;
		auto u = pq.top().second.first;
		auto f = pq.top().second.second;
		pq.pop();
 
		if(f == 1)
		{
			if(disc[u] < d) continue; 
		}
 
		if(f == 0)
		{
			if(dist[u] < d) continue; 
		}
 
		for(auto e: g[u])
		{
			int v = e.first, c = e.second;
			if(f == 0) 
			{
                // relaxation
				if(dist[v] > c + d) 
				{
					dist[v] = c+d;
					pq.push({dist[v], {v,0}});
				}
                // if a better deal exists then check it
				if(disc[v] > d + c/2) 
				{
					disc[v] = d + (c/2);
					pq.push({disc[v], {v,1}});	
				}
			}
 
			if(f==1)
			{
                // if a better deal exists then check it dont half it because coupon is already appliled 
				if(disc[v] > d + c)
				{
					disc[v] = d + c;
					pq.push({disc[v], {v,1}});	
				}
			}
 
		}
	}
 
	cout << disc[n] << endl;
}
 
int main()
{
	
	cin >> n >> m;
	g.resize(n+1);
	dist.resize(n+1);
	disc.resize(n+1);
	for(long long int i = 0; i < m; ++i)
	{
		long long int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
 
	dijkstra();
}
