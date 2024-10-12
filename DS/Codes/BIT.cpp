#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

const int MAXN = 1000005;

ll BIT[MAXN];
ll n;

ll query(ll index){
    ll sum=0;
    while (index > 0)
    {
        sum+=BIT[index];
        index -= index & (-index);
    }
    return sum;
}

void update(ll val,ll index){
    while (index <= n)
    {
       BIT[index]+=val;
       index += index & (-index);   
    }
}

void reset(ll n){
    for(ll i=0;i<=n;i++) BIT[i]=0;
}

int main(){
}

