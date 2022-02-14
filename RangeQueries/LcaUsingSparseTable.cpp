#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define w(x)                int x;cin>>x;while(x-->0)
#define ll                  long long int
#define inf                 1e18
#define mod                 1000000007
#define arin(a)             for (auto &it : a) cin >> it;
#define dbg(ar,st,ed)       for(ll i=st;i<=ed;i++)cout<<ar[i]<<" ";cout<<endl;
#define endl               "\n"
#define ff                  first
#define ss                  second
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

void dfs(vector<ll> adj[],ll node,ll par,ll dep,vector<ll>& depth,vector<vector<ll>>& parents){
    depth[node]=dep;
    parents[node][0]=par;
    ll i=1;
    while((1<<i)<dep){
        parents[node][i]=parents[parents[node][i-1]][i-1];
        i+=1;
    }
    for(auto child:adj[node]){
        if(child!=par){
            dfs(adj,child,node,dep+1,depth,parents);
        }
    }
}

ll lca(ll u,ll v,vector<ll>& depth,vector<vector<ll>>& parents){
    if(depth[u]<depth[v])swap(u,v);
    ll diff = depth[u]-depth[v];

    ll mask = (1<<20);
    while(mask>0){
        if(diff&mask){
            u = parents[u][log2(diff&mask)];
        }
        mask>>=1;
    }
    while(u!=v){
        ll low=0,high=log2(depth[u]-1);
        ll ans=high;
        while(low<=high){
            ll mid = low + (high-low)/2;
            if(parents[u][mid]==parents[v][mid]){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        if(ans==0){
            u=parents[u][ans];
            v=parents[v][ans];
        }
        else{
            u=parents[u][ans-1];
            v=parents[v][ans-1];
        }
    }
    return v;
}

void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> adj[n+1];
    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> depth(n+1);
    vector<vector<ll>> parents(n+1,vector<ll>(25));
    dfs(adj,1,0,1,depth,parents);
    while(q-->0){
        ll u,v;cin>>u>>v;
        ll Lca = lca(u,v,depth,parents);
        cout<<Lca<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    //w(t)solve();
    solve();
}