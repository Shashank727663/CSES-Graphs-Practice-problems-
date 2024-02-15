#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> SegmentTree;

void build(int node, int start, int end) {
    if (start == end) {
        SegmentTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    SegmentTree[node] = SegmentTree[2 * node] ^ SegmentTree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        return 0; // Neutral value for XOR
    }

    if (l <= start && end <= r) {
        return SegmentTree[node];
    }

    int mid = (start + end) / 2;

    return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    int n, q;
    cin >> n >> q;

    arr.resize(n + 1);
    SegmentTree.resize(4 * n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        // XOR sum of values in range [a, b]
        int result = query(1, 1, n, a, b);
        cout << result << endl;
    }

    return 0;
}
