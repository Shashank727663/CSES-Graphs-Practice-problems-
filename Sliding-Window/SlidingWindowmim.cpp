
// //First glance Sloution works on small tcs not very big gives TLE 
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, k;
//     cin >> n >> k;

//     vector<int> nums;
//     nums.reserve(n);

//     int x, a, b, c;

//     for (int i = 0; i < n; i++) {
//         cin >> x >> a >> b >> c;

//         if (i == 0) {
//             nums.push_back(x);
//         } else {
//             int num = ( a * nums[i - 1] + b) % c;
//             nums.push_back(num);
//         }
//     }

//     int l = 0, r = k - 1;
//     int sum = 0;

//     while (l <= r && ( r < n)) {
//         int tSum = INT_MAX;
//         for (int i = l; i <= r; i++) {
//             tSum = min( tSum, nums[i] );
//         }
        

//         sum ^= tSum;
//        l++;
//        r++;
//     }

//     cout << sum;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    int x, a, b, c;

    for (int i = 0; i < n; i++) {
        cin >> x >> a >> b >> c;

        if (i == 0) nums[i] = x;
        else nums[i] = (a * nums[i - 1] + b) % c;
    }

    multiset<int> ms;
    int ans = 0;

    // Build first window
    for (int i = 0; i < k; i++)
        ms.insert(nums[i]);

    ans ^= *ms.begin();  // minimum element

    // Slide window
    for (int i = k; i < n; i++) {
        ms.erase(ms.find(nums[i - k])); // remove outgoing element
        ms.insert(nums[i]);             // add new element

        ans ^= *ms.begin();
    }

    cout << ans;
    return 0;
}
