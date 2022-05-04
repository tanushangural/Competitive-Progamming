#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define w(x)                int x;cin>>x;while(x-->0)
#define int                  long long int
#define mod                 1000000007
#define arin(a) for         (auto &it : a) cin >> it;
#define endl               "\n"
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

class DSU{
    public:
    int *parent;
    int *rank;
    DSU(int v){
        parent = new int[v+1];
        rank = new int[v+1];
        for(int i=1;i<=v;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
 
    int find(int x){
        if(parent[x]==x) return x;
        parent[x]=find(parent[x]); // Path Comparsion
        return parent[x];
    }
 
    void uniun(int x,int y){
        int px = find(x);
        int py = find(y);
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
