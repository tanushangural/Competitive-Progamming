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

class SparseTable{
    private:
        ll N,K;
        ll **st;
        ll *Log,*pw;
    public:
        SparseTable(ll N,vector<ll>& ar){
            ll K = log2(N)+1;
            Log = new ll[N+1];
            pw = new ll[K];
            st = new ll*[N];
            for(ll i=0;i<N;i++)st[i]=new ll[K];
            for(ll i=0;i<N;i++)st[i][0]=ar[i];
            Log[1]=0;for(ll i=2;i<=N;i++) Log[i]=Log[i/2]+1;
            pw[0]=1;for(ll i=1;i<K;i++)pw[i]=2*pw[i-1];
            this->N = N;
            this->K = K;
            for(ll j=1;j<K;j++){
                for(ll i=0;i<N;i++){
                    if(i+pw[j-1]<N)st[i][j] = todoLogic(st[i][j-1],st[i+pw[j-1]][j-1]);
                    else st[i][j]=st[i][j-1];
                }
            }
        }
        ll todoLogic(ll x,ll y);
        ll query(ll l,ll r){
            ll len = r-l+1;
            return todoLogic(st[l][Log[len]],st[r-pw[Log[len]]+1][Log[len]]);
        }
};
int main(){
    
}