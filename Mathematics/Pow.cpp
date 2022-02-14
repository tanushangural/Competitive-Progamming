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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

ll fun(ll n,ll k){
    if(k==0)return 1;
    ll temp = fun(n,k/2);
    if(k&1)return (((temp*temp)%mod)*n)%mod;
    else return (temp*temp)%mod;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    cout<<fun(n,k)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    //w(t)solve();
    solve();
}