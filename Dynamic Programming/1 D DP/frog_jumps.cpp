#include "bits/stdc++.h"
using namespace std;


//MEMOIZATION//SC-->0(N)+O(N)

int f(int ind,vector<int> &heights,vector<int>&dp){
    if(ind==0){
        return 0;
    }
   
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int right=INT_MAX;
    
     int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);//1 step jump
    
    if(ind>1){
     right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);//2 step jump
    }
    
    return dp[ind]=min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);//create dp array size n+1,,initialize with -1
    return f(n-1,heights,dp);
}


//TABULATION//sc-->O(N)

int frogJump2(int n, vector<int> &heights)
{
    vector<int>dp(n,0);//create dp array size n+1,,initialize with -1
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);//first step
        int ss=INT_MAX;
        if(i>1){
           ss=dp[i-2]+abs(heights[i]-heights[i-2]);//second step
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}


//FUETHER SPACE OPTIMIZATION//SC-->O(1)

int frogJump3(int n, vector<int> &heights)
{
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-1]);//first step
        int ss=INT_MAX;
        if(i>1){
           ss=prev2+abs(heights[i]-heights[i-2]);//second step
        }
        int curr=min(fs,ss);
        prev2=prev;
        prev=curr;
    }
    return prev;
}