#include <iostream>
#include <vector>
#include<climits>
#include <stdlib.h>
#include <limits>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<long long> SegmentTree;

void build(int node,int start,int end) {
    if(start == end) {
        SegmentTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    // left subtree
    build(2 * node,start,mid);

    // right subtree

    build(2 * node + 1 , mid + 1 , end);
   SegmentTree[node] = min(SegmentTree[2 * node] , SegmentTree[2 * node + 1]);
}


void update(int node , int start , int end ,int index,int val) {
    if(start == end) {
        arr[index] = val;
        SegmentTree[node] = val;
        return;
    }

    int mid = (start + end) / 2;

    if(index <= mid) {
        // left subtree
        update(2 * node , start,mid,index,val);
    }else {
        update(2 * node + 1 , mid + 1 , end , index,val);
    }


    SegmentTree[node] = min(SegmentTree[2 * node] , SegmentTree[2 * node + 1]);
}


long long query(int node ,int start,int end , int l ,int r) {
    if(start > r || end < l ){
        return INT_MAX;
    }

    if(l <= start && end <= r) {
        return SegmentTree[node];
    }


    int mid = (start + end) / 2;

    return min(query(2 * node , start , mid , l,r)  ,query(2 * node + 1 , mid + 1 , end , l,r));
}

int main() {
    int n,m;
    cin>>n>>m;
    arr.resize(n);
    SegmentTree.resize(4 * n);
    for(int i = 0 ; i < n ; i++) {
        cin>>arr[i];
    }

    build(1,0,n-1);



    while(m--) {
        int a , b,c;
        cin>>a>>b>>c;
        if(a == 1 ) {
            update(1,0,n-1,b-1,c);
        }else if( a == 2 ) {
            cout<<query(1,0,n-1,b-1,c-1)<<endl;
        }
    }
}