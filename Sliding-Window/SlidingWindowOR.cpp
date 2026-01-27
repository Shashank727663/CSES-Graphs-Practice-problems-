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

    long long windowOr = 0;
    long long ans = 0;

    // initial window
    for (int i = 0; i < k; i++) {
        windowOr |= nums[i];
    }
    ans ^= windowOr;

    // sliding window
    for (int i = 1; i + k - 1 < n; i++) {
        windowOr |= nums[i - 1];      // remove left item? (WRONG LOGIC for OR)
        windowOr |= nums[i + k - 1];  // add right item
        ans ^= windowOr;
    }

    cout << ans;
    return 0;
}
