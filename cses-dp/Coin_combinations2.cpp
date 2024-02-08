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
    vector<int>coins(n);
    for(int i = 0 ; i < n ;i++) {
        cin>>coins[i];
    }


    vector<vector<int>>dp(n+1 , vector<int>(x+1));
    for(int i = 0 ; i < n ;i++) {
        dp[i][0] = 1;
    }

    for(int i = n - 1 ; i >= 0 ; i --) {
        for(int sum = 1 ; sum <= x ;sum++ ) {
            int excl = dp[i+1][sum];
            int incl = 0;
            // including if the sum is greater than values of coins to avoid duplicacy
            if(coins[i] <= sum){
                incl = dp[i][sum-coins[i]];
            }

            dp[i][sum] = (incl + excl) % 1000000007;
        }
    }


    cout<<dp[0][x]<<endl;
}