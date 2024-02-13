#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define pb            push_back
#define vi            vector<int>
#define vs            vector<string>
#define vb            vector<bool>
#define F             first
#define S             second
#define pii           pair<int, int>
#define piv           pair<int, vector<int>>
#define vvi           vector< vector<int> >
#define all(p)        p.begin(), p.end()
#define setBit(x)     __builtin_popcountll(x)
#define lb(x,num)     lower_bound(all(x),num)
#define ub(x,num)     upper_bound(all(x),num)
#define FI(i,x,y,inc) for(int i = x; i < y; i += inc)
#define F(i,x)        FI(i,0,x,1)
#define double        long double
#define mod           1000000007

/*----------------------------------------------------------------------------------------------------------------*/
void dfs(string s,unordered_map<string,pair<string,string>>&mp, unordered_map<string,bool>&vis )
     {  if(!mp.count(s)) return;
         vis[s]=1;
        
        cout<<s<<" "<<mp[s].first<<" "<<mp[s].second<<endl;
         //cout<<"aya";
                dfs(mp[s].first,mp,vis);
            

	  return ;
     }
/*----------------------------------------------------------------------------------------------------------------*/
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
    cin>>t;
    while(t--)
    { 
	  int n;
      cin>>n;
      long long int tot=0;
      unordered_map<string,pair<string,string>>mp;
      unordered_map<string,bool>vis;
      for(int i=0;i<n-1;i++){
          string s1,s2,x;
          cin>>s1>>s2>>x;
          tot+=stoll(x);
         
          vis[s1]=false;
          vis[s2]=false;
          mp[s1]={s2,x};
      }
      for(auto i:mp){
          
          vis[i.second.first]=1;
      }
      
      vector<string>q;
      for(auto i:vis){
          if(i.second==false) q.push_back(i.first);
      }
      for(auto i:vis) i.second=false;
      
      for(int i=0;i<q.size();i++){
            if(!vis[q[i]])
                {  // cout<<"YAa"<<endl;
                    dfs(q[i],mp,vis);
                }
      }
      
      cout<<tot<<"$"<<endl;
      
      
      
      
 
    }
    return 0;
}