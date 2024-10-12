#include <iostream>
#include <vector>
using namespace std;

const int MAXN= 1e6 + 5;

vector <int> parent(MAXN);
vector <int> component_size(MAXN);
vector <int> depth(MAXN);

void initialize(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        component_size[i]=1;
        depth[i]=0;
    }
}

int find_parent(int n){
    return (n == parent[n]) ? parent[n] : parent[n] = find_parent(n); 
}

void Merge(int x,int y){
    int px = parent[x];
    int py = parent[y];
    if(depth[px]>=depth[py]){
        parent[py]=px;
        component_size[px]+=component_size[py];
        if(depth[px]==depth[py]) depth[px]++;
    }
    else{
        parent[px]=py;
        component_size[py]+=component_size[px]; 
    }
}

