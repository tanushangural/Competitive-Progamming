#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define w(x)                int x;cin>>x;while(x-->0)
#define ll                  long long int
#define mod                 1000000007
#define arin(a) for         (auto &it : a) cin >> it;
#define endl               "\n"
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

class DSU{
    public:
    ll *parent;
    ll *rank;
    DSU(ll v){
        parent = new ll[v+1];
        rank = new ll[v+1];
        for(ll i=1;i<=v;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
 
    ll find(ll x){
        if(parent[x]==x) return x;
        parent[x]=find(parent[x]); // Path Comparsion
        return parent[x];
    }
 
    void uniun(ll x,ll y){
        ll px = find(x);
        ll py = find(y);
        if(px == py)return;
        if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else{
            parent[py]=px;
            rank[px]+=1;
        }
    }
};
int main(){
    
}