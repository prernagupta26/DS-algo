#include "bits/stdc++.h"
using namespace std;
    //deduct transaction fees on completeion of transaction

    //memoization

    int f(int ind,int buy,int fee,vector<int>&prices,vector<vector<int>>&dp){
        
        if(ind==prices.size())  return 0;
        
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        
        int profit=0;
        
        if(buy==0){
            int buying=-prices[ind]+f(ind+1,1,fee,prices,dp);
            int notbuy=f(ind+1,0,fee,prices,dp);
            
            profit=max(buying,notbuy);
        }
        if(buy==1){
            int sell=prices[ind] -fee +f(ind+1,0,fee,prices,dp);  //deducting the transaction on completion of transaction
            int notsell=f(ind+1,1,fee,prices,dp);
            
            profit=max(sell,notsell);
        }
        return dp[ind][buy]=profit;
        
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return f(0,0,fee,prices,dp);
    }


//TABULATION
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        int profit=0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    int buying=-prices[ind]+ dp[ind+1][1];
                    int notbuy=dp[ind+1][0];
                    
                    profit=max(buying,notbuy);
                }
                if(buy==1){
                    int sell=prices[ind]-fee+dp[ind+1][0];
                    int notsell=dp[ind+1][1];
                    
                    profit=max(sell,notsell);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][0];
    }