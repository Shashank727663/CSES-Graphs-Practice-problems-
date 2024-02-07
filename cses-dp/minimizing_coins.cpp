#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
    int n ,x;
    cin>>n>>x;
    vector<int>values(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> values[i];
    }

    vector<int>dp(x+1,1e9);
    dp[0] = 0;

    for(int i = 1 ; i <= x ;i++) {
        for(int j = 0 ; j < n ; j++) {
            if(values[j] <= i) {
                dp[i] = min(dp[i] , dp[i - values[j]] + 1);
            }
        }
    }

    if(dp[x] == 1e9) {
         cout<<-1<<endl;
    }else {
         cout<<dp[x]<<endl;
    }
}