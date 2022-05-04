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
#define ff                  first
#define ss                  second

class SparseTable{
    private:
        int N,K;
        int **st;
        int *Log,*pw;
    public:
        SparseTable(int N,vector<int>& ar){
            int K = log2(N)+1;
            Log = new int[N+1];
            pw = new int[K];
            st = new int*[N];
            for(int i=0;i<N;i++)st[i]=new int[K];
            for(int i=0;i<N;i++)st[i][0]=ar[i];
            Log[1]=0;for(int i=2;i<=N;i++) Log[i]=Log[i/2]+1;
            pw[0]=1;for(int i=1;i<K;i++)pw[i]=2*pw[i-1];
            this->N = N;
            this->K = K;
            for(int j=1;j<K;j++){
                for(int i=0;i<N;i++){
                    if(i+pw[j-1]<N)st[i][j] = todoLogic(st[i][j-1],st[i+pw[j-1]][j-1]);
                    else st[i][j]=st[i][j-1];
                }
            }
        }
        int todoLogic(int x,int y);
        int query(int l,int r){
            int len = r-l+1;
            return todoLogic(st[l][Log[len]],st[r-pw[Log[len]]+1][Log[len]]);
        }
};
int main(){
    
}