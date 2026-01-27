#include<bits/stdc++.h>
using namespace std; 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k;
    cin >> n >> k; 

    vector<int>nums(n); 

    for(int  i = 0 ; i < n ; i++) { 
        cin >> nums[i];
    }

    int i = 0;
    int j = k; 

    while( j <= n) { 
        set<int>s;
        for(int idx = i ; idx < j ; idx++) { 
            s.insert(nums[idx]);
        }

        cout << s.size() << " "; 
        i++ ; 
        j++;
    }
}