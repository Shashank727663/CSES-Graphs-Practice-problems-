#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<long long> SegmentTree;

void build(int node, int start, int end) {
    if (start == end) {
        SegmentTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    // left subtree
    build(2 * node, start, mid);

    // right subtree
    build(2 * node + 1, mid + 1, end);
    SegmentTree[node] = SegmentTree[2 * node] + SegmentTree[2 * node + 1];
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        SegmentTree[node] = val;
        return;
    }

    int mid = (start + end) / 2;

    if (idx <= mid) {
        // go to the left subtree
        update(2 * node, start, mid, idx, val);
    } else {
        // go to the right subtree
        update(2 * node + 1, mid + 1, end, idx, val);
    }

    // update the current node
    SegmentTree[node] = SegmentTree[2 * node] + SegmentTree[2 * node + 1];
}

long long query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        return 0;
    }

    if (l <= start && end <= r) {
        return SegmentTree[node];
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
    SegmentTree.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            // update query
            update(1, 0, n - 1, b - 1, c);
        } else if (a == 2) {
            // range sum query
            cout << query(1, 0, n - 1, b - 1, c - 1) << endl;
        }
    }

    return 0;
}
