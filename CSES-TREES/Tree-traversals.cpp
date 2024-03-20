#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

void postTrev(const vector<int>& in, const vector<int>& pre, vector<int>& post, int startIn, int startPre, int len) {
    if (len == 0)
        return;

    if (len == 1) {
        post.push_back(pre[startPre]);
        return;
    }

    int root = pre[startPre];

    int idxIn;
    for (int i = startIn; i < startIn + len; i++) {
        if (in[i] == root) {
            idxIn = i;
            break;
        }
    }

    // left subtree
    int leftLen = idxIn - startIn;
    postTrev(in, pre, post, startIn, startPre + 1, leftLen);

    // right subtree
    int rightLen = len - leftLen - 1;
    postTrev(in, pre, post, idxIn + 1, startPre + leftLen + 1, rightLen);

    post.push_back(root);
}

int main() {
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> in(n);
    vector<int> post;

    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    postTrev(in, pre, post, 0, 0, n);

    for (auto x : post) {
        cout << x << " ";
    }

    return 0;
}
