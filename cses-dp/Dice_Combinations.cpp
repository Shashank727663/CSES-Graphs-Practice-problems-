#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int maxi = 1e6;
vector<int>dp(maxi ,  0);
const int MOD = 1e9+7;
int n;
int main()
{
    cin>>n;
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= 6 ; j ++) {
            if( i - j >= 0){
                dp[i] = (  dp[i] + dp[i -j ] ) %  MOD;
            }
        }
    }


    cout<<dp[n]<<endl;
}