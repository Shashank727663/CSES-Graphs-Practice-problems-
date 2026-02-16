#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n , k; 

    cin >> n >> k; 

    vector<long long >nums; 

    for(int i = 0 ; i < n ;i++) { 
        long long num; 
        cin>> num; 
        nums.push_back(num);
    }

  // sliding window
    for (int i = 0; i + k - 1 < n; i++) {
        vector<long long>window; 
        
        for (int j = i; j < i + k; j++) {
            window.push_back(nums[j]);
        }

        sort(window.begin(), window.end());

      if(k % 2 != 0 ) { 
        long long  idx = k / 2; 
        cout<< window[idx] << " ";
      }

      else { 
          long long  idx = k / 2; 
          long long idx2 = ((k/2) - 1); 
        cout<< min(window[idx] , window[idx2]) << " ";
      }
    }



}