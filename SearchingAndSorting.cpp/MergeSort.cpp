#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define w(x)                int x;cin>>x;while(x-->0)
#define ll                  long long int
#define mod                 1000000007
#define arin(a)             for (auto &it : a) cin >> it;
#define dbg(ar,st,ed)       for(ll i=st;i<=ed;i++)cout<<ar[i]<<" ";cout<<endl;
#define endl               "\n"
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

void merge(vector<ll>& ar,ll& l,ll& mid,ll& r){
    vector<ll>temp;
    ll i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(ar[i]<=ar[j])temp.push_back(ar[i++]);
        else temp.push_back(ar[j++]);
    }
    while(i<=mid)temp.push_back(ar[i++]);
    while(j<=r)temp.push_back(ar[j++]);

    for(ll i=l;i<=r;i++){
        ar[i]=temp[i-l];
    }
}

void mergeSort(vector<ll>& ar,ll l,ll r){
    if(l>=r)return;
    ll mid = l+(r-l)/2;
    mergeSort(ar,l,mid);
    mergeSort(ar,mid+1,r);
    merge(ar,l,mid,r);
}




// Inversion Count Problem
//Using Ordered_set
void solve2(){
    ll n;cin>>n;
    vector<ll> ar(n);arin(ar);
    ll ans=0;
    ordered_set set;
    for(ll i=n-1;i>=0;i--){
        if(!set.empty()){
            ans+=set.order_of_key(ar[i]);
        }
        set.insert(ar[i]);
    }
    cout<<ans<<endl;
}
// Brute force O(n^2)
void solve1(){
    ll n;cin>>n;
    vector<ll> ar(n);arin(ar);
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(ar[i]>ar[j])ans+=1;
        }
    }
    cout<<ans<<endl;
}
//Using TwoPointer
ll curAnsUsingTwoPointers(vector<ll>& ar,ll& l,ll& mid,ll& r){
    ll ans=0;
    ll i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(ar[i]<=ar[j]){
            ans+=((j-1)-mid);
            i+=1;
        }
        else j+=1;
    }
    while(i<=mid){
        ans+=((j-1)-mid);
        i+=1;
    }
    return ans;
}
// Using Binary Search O(nlogn)
ll curAnsUsingBs(vector<ll>& ar,ll& l,ll& mid,ll& r){
    ll ans=0;
    for(ll i=l;i<=mid;i++){
        ll low=mid+1,high=r;
        ll idx=-1;
        while(low<=high){
            ll m = (low+high)/2;
            if(ar[m]<ar[i]){
                idx=m;
                low=m+1;
            }
            else high=m-1;
        }
        if(idx!=-1)ans+=(idx-mid);
    }
    return ans;
}
ll inversions(vector<ll>& ar,ll l,ll r){
    if(l>=r)return 0;
    ll ans=0;
    ll mid = (l+r)/2;
    ans+=inversions(ar,l,mid);
    ans+=inversions(ar,mid+1,r);
    ans+=curAnsUsingBs(ar,l,mid,r);
    merge(ar,l,mid,r);
    return ans;
}