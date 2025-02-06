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

}

void floyWarshal(){

}

