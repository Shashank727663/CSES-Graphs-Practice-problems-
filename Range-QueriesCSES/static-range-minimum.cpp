#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include<climits>
using namespace std;

vector<int> arr;
vector<long long> SegmentTree;
void build(int node , int start,int end) {
    if(start == end) {
        SegmentTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    // for left subtree
    build( 2 * node , start,mid);
    // for the right subtree
    build(2 * node +1 , mid + 1 , end);

    SegmentTree[node]  = min(SegmentTree[2 * node] , SegmentTree[2 * node + 1]);
}

long long query(int node ,int start,int end ,int l,int r) {
    if(start > r || end < l ) {
        return INT_MAX;
    }

    if( l <= start && end <= r) {
        return SegmentTree[node];
    }

     int mid = (start + end) / 2;
    // left subtree
    long long a = query(2 * node, start, mid, l, r);
    // right subtree
    long long b = query(2 * node + 1, mid + 1, end, l, r);


    return min(a,b);
}
int main() {
    int n , m;
    cin>>n>>m;
    arr.resize(n);
    SegmentTree.resize(4 * n);
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }


    build(1, 0 , n-1);
   



    while(m--) {
        int l ,r ;
        cin>>l>>r;
        cout<<query(1,0,n-1,l-1,r-1)<<endl;
    }
    

}