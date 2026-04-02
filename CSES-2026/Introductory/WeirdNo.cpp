#include<iostream>

using namespace std; 
void solve(long long int n ) { 
    cout << n << " "; 
    if( n == 1 ) { 
        return; 
    }

    if( n % 2 ==0 ) { 
       n = n / 2; 
    }
    else { 
       n = (3*n) + 1;
    }
    solve(n); 
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int n; 
    cin >> n; 
    solve(n); 
    // while(n > 1) { 
    //     if( n % 2 ==0 ) { 
    //         n = n / 2; 
    //         cout << n << " ";
    //     }
    //     else { 
    //         n = ( n * 3) + 1; 
    //         cout<< n << " ";
    //     }
    // }

    return 0; 
}