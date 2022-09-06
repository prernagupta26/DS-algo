   #include "bits/stdc++.h"
using namespace std;


//MEMOIZATION
   int f(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[0]==0){
                return target/coins[0];
            }
            else return 1e9;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
            int notpick=f(ind-1,target,coins,dp);
            int pick=1e9;
            if(target>=coins[ind]){
                pick=1+f(ind,target-coins[ind],coins,dp);
            }
        return dp[ind][target]=min(pick,notpick);
        
    }
    
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans= f(n-1,target,coins,dp);
        
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }




//TABULATION

     int coinChange(vector<int>& coins, int target) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        //base case
        //for every value of target
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];//no. of coins
            }
            else{
                dp[0][i]=1e9;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                int notpick=dp[i-1][t];
                int pick=1e9;
                
                if(t>=coins[i]){
                    pick=1+dp[i][t-coins[i]];
                }
                
                dp[i][t]=min(pick,notpick);
            }
        }
        
        int ans=dp[n-1][target];
        
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }