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


const ll N = 1000005;
vector<ll> primes;//prime numbers vector
bool isPrime[N];  //CheckPrime
void sieve(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i*i<=N;i++){
        if(isPrime[i]){
            for(ll j=2*i;j<=N;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(ll i=2;i<=N;i++){
        if(isPrime[i])primes.push_back(i);
    }
}


// Smallest prime of every number
ll firstPrime[N+5];
void sieve(){
    memset(firstPrime,0,sizeof(firstPrime));
    firstPrime[0]=firstPrime[1]=1;
    for(ll i=2;i*i<=N;i++){
        if(firstPrime[i]==0){
            firstPrime[i]=i;
            for(ll j=i;j<=N;j+=i){
                if(firstPrime[j]==0)firstPrime[j] = i;
            }
        }
    }
}


int main(){
    
}