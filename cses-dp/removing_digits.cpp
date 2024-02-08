#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    while(n > 0 ){
        string a = to_string(n);
        char maxdigit = '0';
        for(auto x : a ){
            maxdigit = max(maxdigit,x);
        }
        ans++;
        n-=(maxdigit - '0');
    }

    cout<<ans<<endl;
}