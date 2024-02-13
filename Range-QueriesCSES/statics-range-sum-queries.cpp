#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

vector<int> arr;
vector<long long> SegementTree;

void build(int node, int start, int end) {
    if (start == end) {
        SegementTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    // build the left subtree
    build(2 * node, start, mid);
    // building the right subtree
    build(2 * node + 1, mid + 1, end);

    SegementTree[node] = SegementTree[2 * node] + SegementTree[2 * node + 1];
}

long long query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        return 0;
    }

    if (l <= start && end <= r) {
        return SegementTree[node];
    }

    int mid = (start + end) / 2;
    // left subtree
    long long a = query(2 * node, start, mid, l, r);
    // right subtree
    long long b = query(2 * node + 1, mid + 1, end, l, r);

    return a + b;
}

int main() {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    SegementTree.resize(4 * n);  // Adjust the size for a large enough range

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, l - 1, r - 1) << endl;  // Adjust the range for 0-based indexing
    }

    return 0;
}
