#include "bits/stdc++.h"
using namespace std;

//MEMOIZATION

bool f(int ind,int k,vector<int>&a, vector<vector<int>>&dp){
    if(k==0){//target reached
        return true;
    }
    if(ind==0){
        return a[0]==k;
    }
    if(dp[ind][k]!=-1){
        return dp[ind][k];
    }
    
    int notpick=f(ind-1,k,a,dp);
    int pick=false;
    if(k>=a[ind]){
        pick=f(ind-1,k-a[ind],a,dp);
    }
    return dp[ind][k]=pick or notpick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}




//TABULATION


bool subsetSumToK(int n, int k, vector<int> &a) {
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    
    for(int i=0;i<n;i++){
        dp[i][0]=true;//target 0 for every index
    }
    
    if(a[0]<=k){
        dp[0][a[0]]=true; //at 0 index target achived //target equal to 0 index value
    }
    
    for(int i=1;i<n;i++){//i ==index
        for(int j=1;j<=k;j++){//j==target
            int notpick=dp[i-1][j];//target same because element not picked
            
            int pick=false;
            if(j>=a[i]){
                pick=dp[i-1][j-a[i]];
            }
            
            dp[i][j]=pick or notpick;
        }
    }
    return dp[n-1][k];
}