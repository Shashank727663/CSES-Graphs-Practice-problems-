#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
vector<int>adj[200005];
bool done[200005];
int ans = 0;



void dfs(int pre, int cur) {
	for (int i : adj[cur]) {
		if (i != pre) {
			dfs(cur, i);
			if (!done[i] && !done[cur]) done[cur] = done[i] = 1, ans++;
		}
	}
}

int main(){
  int n;
  cin>>n;
  if( n == 1) {
    cout<<0<<endl;
    return 0;
  }

for(int i = 0 ; i < n ; i++) {
    int u , v;
    cin>> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}


dfs(0,1);
cout<<ans<<endl;
}