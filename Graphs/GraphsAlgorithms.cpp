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

//Direction for grid base graphs
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

//dfs traversal
void dfs(vector<int> adj[],int node,vector<bool>& visited){
    visited[node]=true;
    for(auto nbr:adj[node]){
        if(!visited[nbr])dfs(adj,nbr,visited);
    }
}

// for shortest path in weigthed graph
void DijkstraAlgorithm(vector<pair<int,int>> adj[],int V,int src){
    vector<bool> visited(V+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; // {dist,0};
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
int PrimsAlgorithm(vector<pair<int,int>> adj[],int V,int src){
    vector<bool> visited(V+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; // {dist,0};
    int dist[V+1]={0};
    q.push({0,src});
    int minimumcost=0;
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
vector<int> topologicalSort(vector<int> adj[],int V){
    vector<int> ans;
    int indeg[V+1]={0};
    for(int i=1;i<=V;i++){
        for(auto e:adj[i]){
            indeg[e]+=1;
        }
    }
    queue<int> q;
    for(int i=1;i<=V;i++){
        if(indeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();q.pop();
        ans.push_back(cur);
        for(auto nbr:adj[cur]){
            indeg[nbr]-=1;
            if(indeg[nbr]==0)q.push(nbr);
        }
    }
    return ans;
}

// For aint pair of vertices shortest path Algorithm
void FloydWarshaintAlgorithm(vector<vector<int>>& grid,int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)grid[i][j]=0;
                grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);;
            }
        }
    }
}
 