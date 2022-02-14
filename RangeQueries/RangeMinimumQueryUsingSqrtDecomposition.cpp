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


void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> ar(n);arin(ar);
    ll len = sqrt(n)+1;
    vector<ll> b(len,inf);
    for(ll i=0;i<n;i++)b[i/len]=min(b[i/len],ar[i]);
    while(q-->0){
        ll l,r;cin>>l>>r;
        l-=1,r-=1;
        ll i=l;
        ll ans=inf;
        while(i<=r){
            if(i%len==0 && (i+len-1)<=r){
                ans = min(ans,b[i/len]);
                i+=len;
            }
            else{
                ans = min(ans,ar[i]);
                i+=1;
            }
        }
        cout<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    //w(t)solve();
    solve();
}