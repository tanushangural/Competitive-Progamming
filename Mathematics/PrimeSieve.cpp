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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


const int N = 1000005;
vector<int> primes;//prime numbers vector
bool isPrime[N];  //CheckPrime
void sieve(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<=N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<=N;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(isPrime[i])primes.push_back(i);
    }
}

// Smaintest prime of every number
int firstPrime[N+5];
void sieve(){
    memset(firstPrime,-1,sizeof(firstPrime));
    for(int i=2;i*i<=N;i++){
        if(firstPrime[i]==-1){
            for(int j=2*i;j<=N;j+=i){
                if(firstPrime[j]==-1)firstPrime[j] = i;
            }
        }
    }
}

int32_t main(){
    
}