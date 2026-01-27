#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> nums(n);
    nums[0] = x;

    for (int i = 1; i < n; i++) {
        nums[i] = (a * nums[i-1] + b) % c;
    }

    long long windowXor = 0;
    long long ans = 0;

    // initial window
    for (int i = 0; i < k; i++) {
        windowXor ^= nums[i];
    }
    ans ^= windowXor;

    // sliding window
    for (int i = 1; i + k - 1 < n; i++) {
        windowXor ^= nums[i - 1];      // remove left item
        windowXor ^= nums[i + k - 1];  // add right item
        ans ^= windowXor;
    }

    cout << ans;
    return 0;
}
