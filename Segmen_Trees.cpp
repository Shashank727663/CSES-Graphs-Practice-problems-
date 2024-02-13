#include <iostream>
#include <vector>
#include <algorithm>
// Add any other necessary header files here

using namespace std;

const int N = 1e5;

int segmentTree[N];
int a[N];
void build(int node , int start,int end) {
    if(start == end) {
        segmentTree[node] = a[start];
        return;
    }


    int mid = (start + end) / 2;
    // for left subtree
    build(2 * node , start,mid);

    // for right subtree
    build(2 * node + 1 , mid + 1 , end);


    // updating for sum entries (this line keeps changing on problem statement)
    segmentTree[node] = segmentTree[2*node] + segmentTree[2*node + 1];
}


int query(int node , int start,int end ,int l ,int r ) {
    if(start  > r || end < l){
        return 0;
    }

    if(l <= start && end <= r) {
        return segmentTree[node];
    }

    int mid = (start + end)/2;
    // from the left subtree 
    int q1 = query(2 * node , start,mid , l ,r);
    // from the right subtree
    int q2 = query(2* node + 1 , mid + 1 ,end,l,r);
    return q1 + q2;
}


int main() {
    int n;
    cin>>n;

    for(int i = 0 ; i < n ; i++) {
        cin>>a[i];
    }

    build(1,0,n-1);
    // for(int i = 1 ; i <= 15 ;i++) {
    //     cout<<segmentTree[i]<<endl;
    // }

    int ans = query(1,0,n-1,1,5);
    cout<<ans<<endl;


}

