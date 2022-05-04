#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define w(x)                int x;cin>>x;while(x-->0)
#define int                  long long int
#define mod                 1000000007
#define arin(a)             for (auto &it : a) cin >> it;
#define dbg(ar,st,ed)       for(int i=st;i<=ed;i++)cout<<ar[i]<<" ";cout<<endl;
#define endl               "\n"
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

void merge(vector<int>& ar,int& l,int& mid,int& r){
    vector<int>temp;
    int i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(ar[i]<=ar[j])temp.push_back(ar[i++]);
        else temp.push_back(ar[j++]);
    }
    while(i<=mid)temp.push_back(ar[i++]);
    while(j<=r)temp.push_back(ar[j++]);

    for(int i=l;i<=r;i++){
        ar[i]=temp[i-l];
    }
}

void mergeSort(vector<int>& ar,int l,int r){
    if(l>=r)return;
    int mid = l+(r-l)/2;
    mergeSort(ar,l,mid);
    mergeSort(ar,mid+1,r);
    merge(ar,l,mid,r);
}




// Inversion Count Problem
//Using Ordered_set
void solve2(){
    int n;cin>>n;
    vector<int> ar(n);arin(ar);
    int ans=0;
    ordered_set set;
    for(int i=n-1;i>=0;i--){
        if(!set.empty()){
            ans+=set.order_of_key(ar[i]);
        }
        set.insert(ar[i]);
    }
    cout<<ans<<endl;
}
// Brute force O(n^2)
void solve1(){
    int n;cin>>n;
    vector<int> ar(n);arin(ar);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ar[i]>ar[j])ans+=1;
        }
    }
    cout<<ans<<endl;
}
//Using TwoPointer
int curAnsUsingTwoPointers(vector<int>& ar,int& l,int& mid,int& r){
    int ans=0;
    int i=l,j=mid+1;
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
int curAnsUsingBs(vector<int>& ar,int& l,int& mid,int& r){
    int ans=0;
    for(int i=l;i<=mid;i++){
        int low=mid+1,high=r;
        int idx=-1;
        while(low<=high){
            int m = (low+high)/2;
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
int inversions(vector<int>& ar,int l,int r){
    if(l>=r)return 0;
    int ans=0;
    int mid = (l+r)/2;
    ans+=inversions(ar,l,mid);
    ans+=inversions(ar,mid+1,r);
    ans+=curAnsUsingBs(ar,l,mid,r);
    merge(ar,l,mid,r);
    return ans;
}