#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int maxi = 1e6;
vector<int>dp(maxi ,  -1);
const int MOD = 1e9+7;
vector<int>coins;

int n,x;

int main() {
    cin>>n>>x;
    coins.resize(n);
    for(int i = 0 ; i < n; i++) {
        cin>>coins[i];
    }

 
    dp[0] = 1;
    for(int w = 0 ; w <= x ; w++) {
        for(int i = 1 ; i <= n ;i++){
            if(w - coins[i - 1] >= 0 ) {
                // pick
                dp[w] = dp[w] + dp[w - coins[i-1]];
                dp[w] = dp[w] % MOD;
            }
        }
    }

    cout<<dp[x]<<endl;



}