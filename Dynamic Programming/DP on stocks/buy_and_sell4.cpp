
#include "bits/stdc++.h"
using namespace std;
 
 //AT MAX K TRANSACTIONS
 
 //0--> can buy  //1 can not buy
    
    //MEMOIZATION
    
    int f(int ind,int buy,int cap,vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(cap==0)  return 0;
        if(ind==prices.size())  return 0;
        
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        
        int profit=0;
        if(buy==0){//can buy
            int buying=-prices[ind]+f(ind+1,1,cap,prices,dp);
            int notbuy=f(ind+1,0,cap,prices,dp);
            
            profit=max(buying,notbuy);
        }
        
        if(buy==1){//cannot buy
            int sell=prices[ind]+f(ind+1,0,cap-1,prices,dp);
            int notsell=f(ind+1,1,cap,prices,dp);
            
            profit=max(sell,notsell);
        }
        return dp[ind][buy][cap]=profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        //changing parameters-->
        //ind,buy,cap  //3d vector
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        return f(0,0,k,prices,dp);
    }



     //0--> can buy  //1 can not buy
    
   //TABULATION
    
 
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        //changing parameters-->
        //ind,buy,cap  //3d vector
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        //AS WE INTIALIZES DP ARRAY WITH 0--->BASE CASES ARE ALREADY COVERED
        
        
        //base cases
        //cap==0
//         for(int ind=0;ind<n;ind++){
//             for(int buy=0;buy<=1;buy++){
//                 dp[ind][buy][0]=0;
//             }
//         }
        
//         //ind==n
//         for(int buy=0;buy<=1;buy++){
//             for(int cap=0;cap<=k;cap++){
//                 dp[n][buy][cap]=0;
//             }
//         }
        
        int profit=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    
                    if(buy==0){//can buy
                        int buying=-prices[ind]+dp[ind+1][1][cap];
                        int notbuy= dp[ind+1][0][cap];
                        
                        profit=max(buying,notbuy);
                    }
                    if(buy==1){//cannot buy-->we can sell
                        int sell=prices[ind]+dp[ind+1][0][cap-1];
                        int notsell=dp[ind+1][1][cap];
                        
                        profit=max(sell,notsell);
                    }
                    dp[ind][buy][cap]=profit;
                }
            }
        }
        return dp[0][0][k];
    }