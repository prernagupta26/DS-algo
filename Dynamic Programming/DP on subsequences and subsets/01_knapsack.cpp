   #include "bits/stdc++.h"
using namespace std;

//MEMOIZATION
int f(int ind,int capacity,vector<int>&val,vector<int>&wt, vector<vector<int>>&dp){
    if(ind==0){
        if(wt[0]<=capacity){
            return val[0];
        }
        else{
            return 0;
        }
    }
    if(dp[ind][capacity]!=-1){
        return dp[ind][capacity];
    }
    int notpick=f(ind-1,capacity,val,wt,dp);
    int pick=-1e9;
    if(wt[ind]<=capacity){
        pick=val[ind]+f(ind-1,capacity-wt[ind],val,wt,dp);
        }
    return dp[ind][capacity]=max(pick,notpick);
}

int knapsack(vector<int> wt, vector<int> val, int n, int capacity) 
{
    vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
	return f(n-1,capacity,val,wt,dp);
}


//TABULATION
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
   vector<vector<int>>dp(n,vector<int>(W+1,0));
    
    for(int i=wt[0];i<=W;i++){
        dp[0][i]=val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=W;j++){
            int notpick=dp[i-1][j];
            int pick=-1e9;
            if(j>=wt[i]){
                pick=val[i]+dp[i-1][j-wt[i]];
            }
            dp[i][j]=max(pick,notpick);
        }
    }
    return dp[n-1][W];

}