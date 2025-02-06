#include <iostream>
#include <vector>
#include <set>
#define ll long long int
using namespace std;

vector <pair<ll,ll>> v[300005];

void djikstra(ll source,ll nodes){
    // Single source shortest path in an undirected/directed graph with non negative edge weights
    vector <bool> vis(nodes+1,false);
    vector <bool> par(nodes+1,0);
    vector <ll>   dis(nodes+1,1e15);
    set <pair<ll,ll>> s;
    dis[source]=0;
    s.insert({source,dis[source]});
    while (!s.empty())
    {
        pair <ll,ll> p = *s.begin();
        s.erase(s.begin());
        if(vis[p.first]) continue;
        vis[p.first]=true;
        
        for(auto z:v[p.first]){
           if(dis[z.first] > (dis[p.first]+z.second)){
              dis[z.first] = dis[p.first]+z.second;
              par[z.first] = p.first;
           }
        }
    }
    for(ll i=1;i<=nodes;i++){
        if(vis[i]) cout<<dis[i]<<' ';
        else       cout<<"Not Reachable ";
    }
}

void bellmanFord(){
   // useful in directed graphs with negative edge weight but non negative cycles
   // non negative cycle means the one can make infinite rounds of that bringing down the ans

    ll dis[n+1];
    ll lim = 1e12;
    for(ll i=1;i<=n;i++){
        if(i==source) dis[i]=0;
        else          dis[i]=lim;
    }
    for(int i=1;i<n;i++){
       for(int node=1;node<=n;node++){
           if(dis[node] == lim) continue;
           for(auto z:v[node]){
               if((dis[node] + z.second) < dis[z.first])  dis[z.first] = dis[node] + z.second;
           }
       }
    }
}

void floyWarshal(){
   // Used tp get shortest distance between any two nodes in a
   // 1) Undirected graph with non - negative edges
   // 2) directed graph with non - negative cycle
   ll dp[n+1][n+1];
   ll lim = 1e12;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j != i) dp[i][j] = lim;
            else       dp[i][j] = 0;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(auto z:v[i]) dp[i][z.first] = z.second; 
    }
   
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][k] < lim && dp[k][j] < lim){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
}

