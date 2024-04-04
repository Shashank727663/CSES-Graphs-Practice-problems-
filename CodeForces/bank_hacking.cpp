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


int n;
vector<int>strengths;
vector<vector<int>>adj;
  vector<set<int>> semiNeighbors;
  vector<int>vis;
int main() {
    cin >> n;
    strengths.resize(n + 2);
    adj.resize(n + 2);

    vis.resize( n  + 2 , 0);
    // 0 --> online 
    // 1 -----> offline
    for(int i = 1 ; i <= n ; i ++) {
        int u;
        cin >> u;
        strengths.push_back(u);
    }
    for(int i =1 ; i < n ; i ++) {
        int u , v;
        cin >> u >>v;
        adj[u].push_back(v);
    }
    
  
     
 


    // Find the maximum value in the strengthsay
    int maxValue = *max_element(strengths.begin(), strengths.end());

    // Check for duplicate occurrences of the maximum value
    int count = 0;
    for (int num : strengths) {
        if (num == maxValue) {
            count++;
        }
    }


  if(count >1 ) {
    maxValue++;
  }


    queue<int>q;
    q.push(maxValue);


    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto  x : adj[node]) {
            if(!vis[x]) {
               
                strengths[x] = strengths[x] + 1;
              // finding neigbours 
              int next = adj[x][0]; 
          
              strengths[next] += 1;
                //bank hacking 
                if(maxValue >= strengths[x]) {
                    vis[x] = 1;
                }
            }
        }
    }



    cout <<maxValue<<endl;
}
