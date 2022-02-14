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

//Direction for grid base graphs
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};

//dfs traversal
void dfs(vector<ll> adj[],ll node,vector<bool>& visited){
    visited[node]=true;
    for(auto nbr:adj[node]){
        if(!visited[nbr])dfs(adj,nbr,visited);
    }
}

// for shortest path in weigthed graph
void DijkstraAlgorithm(vector<pair<ll,ll>> adj[],ll V,ll src){
    vector<bool> visited(V+1,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q; // {dist,0};
    q.push({0,src});
    while(!q.empty()){
        auto cur = q.top();q.pop();
        if(visited[cur.second])continue;
        visited[cur.second]=true;
        for(auto nbr:adj[cur.second]){
            q.push({nbr.second+cur.first,nbr.first});
        }
    }
}

// for minimum spanning tree
ll PrimsAlgorithm(vector<pair<ll,ll>> adj[],ll V,ll src){
    vector<bool> visited(V+1,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q; // {dist,0};
    ll dist[V+1]={0};
    q.push({0,src});
    ll minimumcost=0;
    while(!q.empty()){
        auto cur = q.top();q.pop();
        if(visited[cur.second])continue;
        visited[cur.second]=true;
        minimumcost+=cur.first;
        for(auto nbr:adj[cur.second]){
            q.push({nbr.second,nbr.first});
        }
    }
    return minimumcost;
}

// Topological sort using bfs
vector<ll> topologicalSort(vector<ll> adj[],ll V){
    vector<ll> ans;
    ll indeg[V+1]={0};
    for(ll i=1;i<=V;i++){
        for(auto e:adj[i]){
            indeg[e]+=1;
        }
    }
    queue<ll> q;
    for(ll i=1;i<=V;i++){
        if(indeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        ll cur = q.front();q.pop();
        ans.push_back(cur);
        for(auto nbr:adj[cur]){
            indeg[nbr]-=1;
            if(indeg[nbr]==0)q.push(nbr);
        }
    }
    return ans;
}

// For all pair of vertices shortest path Algorithm
void FloydWarshallAlgorithm(vector<vector<ll>>& grid,ll n){
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(i==j)grid[i][j]=0;
                grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);;
            }
        }
    }
}
 