#include<iostream>
#include<math.h>
using namespace std; 

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n; 
    cin >> n; 
    long long int sum = 0; 
    long long int realSum = n * (n+1)/ 2;
    for(int i = 0 ; i < n - 1;i++) { 
        int num; 
        cin >> num; 
        sum += num;
    }

    cout<< abs(realSum - sum); 

}