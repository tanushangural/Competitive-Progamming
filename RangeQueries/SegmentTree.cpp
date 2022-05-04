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

class SegTree{
    int *t,*lazy;
    public:
        SegTree(int n){
            t = new int[4*n+5];
            lazy = new int[4*n+5];
            for(int i=0;i<4*n+5;i++)lazy[i]=0;
        }

        int todoLogic(int x,int y);
        
        void build(int idx,int tl,int tr,vector<int>& v){
            if(tl == tr){
                t[idx]=v[tl];
                return;
            }
            int mid = (tl+tr)/2;
            build(2*idx,tl,mid,v);
            build(2*idx+1,mid+1,tr,v);
            t[idx]=todoLogic(t[2*idx],t[2*idx+1]);
        }

        void lazyUpdate(int& idx,int& s,int& mid,int& e){
            t[2*idx]+=lazy[idx]*(mid-s+1);
            t[2*idx+1]+=lazy[idx]*(e-mid);
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
            lazy[idx]=0;
        }
        int query(int idx,int tl,int tr,int ql,int qr){
            if(ql>tr || qr<tl) return 0; // return value can differ according to type of query
            if(tl>=ql && tr<=qr)return t[idx];
            int mid = (tl+tr)/2;
            lazyUpdate(idx,tl,mid,tr);
            int left = query(2*idx,tl,mid,ql,qr);
            int right = query(2*idx+1,mid+1,tr,ql,qr);
            return todoLogic(left,right);
        }
        void updateVal(int idx,int tl,int tr,int& val,int& pos){
            if(tl == tr){
                t[idx]=val;
                return;
            }
            int mid = (tl+tr)/2;
            if(pos<=mid)updateVal(2*idx,tl,mid,val,pos);
            else updateVal(2*idx+1,mid+1,tr,val,pos);
            t[idx]=todoLogic(t[2*idx],t[2*idx+1]);
        }
        void updateRange(int idx,int tl,int tr,int& val,int l,int r){
            if(l>tr || r<tl)return;
            if(tl>=l && tr<=r){
                t[idx]+=val*(tr-tl+1);
                lazy[idx]+=val;
                return;
            }
            int tm = (tl+tr)/2;
            lazyUpdate(idx,tl,tm,tr);
            updateRange(2*idx,tl,tm,val,l,r);
            updateRange(2*idx+1,tm+1,tr,val,l,r);
            t[idx]=todoLogic(t[2*idx],t[2*idx+1]);
        }
};

int SegTree::todoLogic(int x,int y){
    return x+y;
}


/*
SegTree st(n);
st.build(1,0,n-1,ar);
*/
int main(){
    
}