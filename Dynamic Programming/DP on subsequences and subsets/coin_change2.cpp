   #include "bits/stdc++.h"
using namespace std;

//MEMOIZATION
int f(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            return (target%coins[0]==0);
                
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int notpick=f(ind-1,target,coins,dp);
        int pick=0;
        if(target>=coins[ind]){
            pick=f(ind,target-coins[ind],coins,dp);
        }
        return dp[ind][target]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }


//TABULATION
int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       
        for(int t=0;t<=amount;t++){
            dp[0][t]=t%coins[0]==0;//whether its possible or not
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notpick=dp[i-1][j];
                int pick=0;
                if(j>=coins[i]){
                    pick=dp[i][j-coins[i]];
                }
                dp[i][j]=pick+notpick;
            }
        }
        return dp[n-1][amount];
    }