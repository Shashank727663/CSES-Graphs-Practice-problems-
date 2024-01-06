#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
using namespace std;


int main() {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    long long int sum = n * (n+1) / 2;

    long long int arrsum = 0;
    for(int i=0; i<n; i++) {
        arrsum += arr[i];
    }

    cout << sum - arrsum << endl;
}