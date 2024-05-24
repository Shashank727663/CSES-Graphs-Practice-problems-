#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
const int maxN = 505;

bool used[maxN];
int N, M, K, cnt, mt[maxN];
vector<int> adj[maxN];
vector<pii> pairs;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N  >> M >> K;
    for(int i = 0 ; i < K ; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    
    // Initialize matching array
    fill(mt, mt + maxN, -1);

    for(int i = 1; i <= M; i++) {
        // Reset used array before each iteration
        fill(used + 1, used + N + 1, false);
        try_kuhn(i);
    }

    cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(mt[i]) {
            pairs.push_back(make_pair(i, mt[i]));
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(pii P : pairs)
        printf("%d %d\n", P.first, P.second);
}
