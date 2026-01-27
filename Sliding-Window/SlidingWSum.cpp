
// First glance Sloution works on small tcs not very big gives TLE 
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
//         int tSum = 0;
//         for (int i = l; i <= r; i++) {
//             tSum += nums[i];
//         }
        

//         if (sum == 0) sum = tSum;
//         else sum ^= tSum;
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
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> nums(n);
    nums[0] = x;

    for (int i = 1; i < n; i++) {
        nums[i] = (a * nums[i - 1] + b) % c;
    }

    long long sum = 0;
    long long windowSum = 0;

    // build first window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    sum ^= windowSum;

    // slide window
    for (int l = 1; l + k - 1 < n; l++) {
        windowSum -= nums[l - 1];     // remove left
        windowSum += nums[l + k - 1]; // add right
        sum ^= windowSum;
    }

    cout << sum;
    return 0;
}
