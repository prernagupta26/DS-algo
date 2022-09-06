#include "bits/stdc++.h"
using namespace std;

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
//can buy any no. of times

//MEMOIZATION
  int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size()){  //days exhausted
            return 0;   //return 0 if bought sand not sold
        }
        
        int profit;
    
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
        
        if(buy==1){//allowed to buy
            int buying=-prices[ind]+f(ind+1,0,prices,dp);//in next not allowed to buy
            int notbuy= f(ind+1,1,prices,dp);  //in next allowed to buy
            
            profit=max(buying,notbuy);
        }
        else{//not allowed to buy // selling
            int sell=prices[ind]+f(ind+1,1,prices,dp);//as we have sold then we can buy next time
            int notsell=f(ind+1,0,prices,dp);//not sold//so cannnot buy next day
            
            profit=max(sell,notsell);
        }
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return f(0,1,prices,dp);
    }




     // TABULATION
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //0-->can buy  1-->notbuy
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
       dp[n][1]=dp[n][0]=0;
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                
                if(j==0){//can buy
                    int buy=-prices[i]+dp[i+1][1];
                    int notbuy=dp[i+1][0];
                    
                    profit=max(buy,notbuy);
                }
               if(j==1){//can sell
                    int sell=prices[i]+dp[i+1][0];
                    int notsell=dp[i+1][1];
                                          
                    profit=max(sell,notsell);
                }
            
               dp[i][j]=profit;
            }
        }
            return dp[0][0];
    }



     //TABULATION
    
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));//intializing with 0 no need to write base cases
        //size-->n+2 because we are dealing with ind+2 in code
        
        // for(int buy=0;buy<2;buy++){
        //     dp[n][buy]=0;
        // }
        //dp[n][0]=dp[n][1]=0 //same thing as above
        
        int profit=0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    int buying=-prices[ind]+dp[ind+1][1];
                    int notbuy=dp[ind+1][0];
                    
                    profit=max(buying,notbuy);
                }
                if(buy==1){
                    int sell=prices[ind]+dp[ind+2][0];
                    int notsell=dp[ind+1][1];
                    
                    profit=max(sell,notsell);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][0];
    }