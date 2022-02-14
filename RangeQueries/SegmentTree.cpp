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

class SegTree{
    ll *t,*lazy;
    public:
        SegTree(ll n){
            t = new ll[4*n+5];
            lazy = new ll[4*n+5];
            for(ll i=0;i<4*n+5;i++)lazy[i]=0;
        }

        ll todoLogic(ll x,ll y);
        
        void build(ll idx,ll tl,ll tr,vector<ll>& v){
            if(tl == tr){
                t[idx]=v[tl];
                return;
            }
            ll mid = (tl+tr)/2;
            build(2*idx,tl,mid,v);
            build(2*idx+1,mid+1,tr,v);
            t[idx]=todoLogic(t[2*idx],t[2*idx+1]);
        }

        void lazyUpdate(ll& idx,ll& s,ll& mid,ll& e){
            t[2*idx]+=lazy[idx]*(mid-s+1);
            t[2*idx+1]+=lazy[idx]*(e-mid);
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
            lazy[idx]=0;
        }
        ll query(ll idx,ll tl,ll tr,ll ql,ll qr){
            if(ql>tr || qr<tl) return 0; // return value can differ according to type of query
            if(tl>=ql && tr<=qr)return t[idx];
            ll mid = (tl+tr)/2;
            lazyUpdate(idx,tl,mid,tr);
            ll left = query(2*idx,tl,mid,ql,qr);
            ll right = query(2*idx+1,mid+1,tr,ql,qr);
            return todoLogic(left,right);
        }
        void updateVal(ll idx,ll tl,ll tr,ll& val,ll& pos){
            if(tl == tr){
                t[idx]=val;
                return;
            }
            ll mid = (tl+tr)/2;
            if(pos<=mid)updateVal(2*idx,tl,mid,val,pos);
            else updateVal(2*idx+1,mid+1,tr,val,pos);
            t[idx]=todoLogic(t[2*idx],t[2*idx+1]);
        }
        void updateRange(ll idx,ll tl,ll tr,ll& val,ll l,ll r){
            if(l>tr || r<tl)return;
            if(tl>=l && tr<=r){
                t[idx]+=val*(tr-tl+1);
                lazy[idx]+=val;
                return;
            }
            ll tm = (tl+tr)/2;
            lazyUpdate(idx,tl,tm,tr);
            updateRange(2*idx,tl,tm,val,l,r);
            updateRange(2*idx+1,tm+1,tr,val,l,r);
            t[idx]=todoLogic(t[2*idx],t[2*idx+1]);
        }
};

ll SegTree::todoLogic(ll x,ll y){
    return x+y;
}


/*
SegTree st(n);
st.build(1,0,n-1,ar);
*/
int main(){
    
}