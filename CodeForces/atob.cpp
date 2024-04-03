#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include<climits>
#include <queue>
using namespace std;
typedef long long int lli ;

int  a  , b;

int main () {
    cin >>a >> b;
    vector<int>path;
    int ok = 1;
    while(b > a) {
        path.push_back(b);
        if( (b & 1) == 0) {
            b = b  / 2;
        }
    }
}