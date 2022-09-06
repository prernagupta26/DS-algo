 #include "bits/stdc++.h"
using namespace std;

   //after selling take cooldown perdiod of one day
   //cannot buy immediately after selling

   //MEMOIZATION

    int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        
        if(ind>=prices.size())  return 0;//because we are doing ind+2 so it can go beyond n
        
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        
        int profit=0;
        
        if(buy==0){
            int buying=-prices[ind]+f(ind+1,1,prices,dp);
            int notbuy=f(ind+1,0,prices,dp);
            
            profit=max(buying,notbuy);
        }
        
        if(buy==1){
            int sell=prices[ind]+f(ind+2,0,prices,dp);//doing ind+2 //colldown period
            
            int notsell=f(ind+1,1,prices,dp);
            
            profit=max(sell,notsell);
            
        }
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return f(0,0,prices,dp);
    }