#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> SegmentTree;

void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        SegmentTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildSegmentTree(2 * node + 1, start, mid);
    buildSegmentTree(2 * node + 2, mid + 1, end);

    SegmentTree[node] = SegmentTree[2 * node + 1] + SegmentTree[2 * node + 2];
}

void update(int node, int start, int end, int l, int r, int u) {
    if (start > r || end < l) {
        return;
    }

    if (start >= l && end <= r) {
        SegmentTree[node] += u;
        return;
    }

    int mid = (start + end) / 2;
    update(2 * node + 1, start, mid, l, r, u);
    update(2 * node + 2, mid + 1, end, l, r, u);

    SegmentTree[node] = SegmentTree[2 * node + 1] + SegmentTree[2 * node + 2];
}

long long query(int node, int start, int end, int k) {
    if (start == end) {
        return SegmentTree[node];
    }

    int mid = (start + end) / 2;
    if (k <= mid) {
        return query(2 * node + 1, start, mid, k);
    } else {
        return query(2 * node + 2, mid + 1, end, k);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    SegmentTree.resize(4 * n);  // Adjust the size as needed

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    buildSegmentTree(0, 0, n - 1);

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(0, 0, n - 1, a - 1, b - 1, u);
        } else if (t == 2) {
            int k;
            cin >> k;
            cout << query(0, 0, n - 1, k - 1) << endl;
        }
    }

    return 0;
}
