#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int lli;

int main() {
    lli n, m;
    cin >> n >> m;
    
    if (n >= m) {
        cout << n - m << endl;
        return 0;
    }

    vector<int> visited(2 * m + 1, 0);
    queue<pair<lli, lli>> q;
    q.push({n, 0});
    visited[n] = 1;

    while (!q.empty()) {
        lli current = q.front().first;
        lli steps = q.front().second;
        q.pop();

        if(current == m ) {
            cout <<steps<<endl;
            return 0;
        }
        if(current * 2 <= 2 * m && !visited[current*2]){
            q.push({current*2 , steps+1});
            visited[current*2] = 1;
        }

        if(current -1 > 0  && !visited[current-1]){
            q.push({current-1 , steps+1});
            visited[current-1] = 1;
        }


    }

    return 0;
}
