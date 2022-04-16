#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define w(x)                int x;cin>>x;while(x-->0)
#define int                  long long int
#define inf                 1e18
#define mod                 1000000007
#define arin(a)             for (auto &it : a) cin >> it;
#define dbg(ar,st,ed)       for(int i=st;i<=ed;i++)cout<<ar[i]<<" ";cout<<endl;
#define endl               "\n"

int fun(int n,int k){
    if(k==0)return 1;
    int temp = fun(n,k/2);
    if(k&1)return (((temp*temp)%mod)*n)%mod;
    else return (temp*temp)%mod;
}

void solve(){
    int n,k;
    cin>>n>>k;
    cout<<fun(n,k)<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    //w(t)solve();
    solve();
}