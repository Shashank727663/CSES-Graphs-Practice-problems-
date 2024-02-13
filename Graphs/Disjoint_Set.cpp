#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
   public:
     vector<int>rank,parent,size;
     
     
    DisjointSet(int n ) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0 ; i <= n;i++) {
            parent[i] = i;
            size[i] =1;
        }
    }
    
    
    int findPar(int node){
        if(node == parent[node]) {
            return node;
        }
        
        return parent[node] = findPar(parent[node]);
    }
    
    
    void unionByRank(int u , int v) {
        int p_u = findPar(u);
        int p_v = findPar(v);
        if(p_u == p_v) {
            return;
        }
        
        if(rank[p_u] < rank[p_u]) {
            parent[p_u] = p_v;
        }
        
        else if(rank[p_u] > rank[p_v]) {
            parent[p_v] = p_v;
        }
        
        else{
            parent[p_v] = p_u;
            rank[p_u]++;
        }
        }
        
        
        void unionBySize(int u , int v) {
            int p_u = findPar(u);
            int p_v = findPar(v);
            if(p_u == p_v) {
                return;
            }
            
            if(size[p_u] < size[p_v]) {
                parent[p_u] = p_v;
                size[p_v] += size[p_u];
            }else {
                parent[p_v] = p_u;
                size[p_u] += size[p_v];
            }
        }

    
};