    #include "bits/stdc++.h"
using namespace std;
    //ONLY TWO TRANSACTIONS ALLOWED
    
    //atmost two transactions   //0->can buy  //1 cannot buy
    int f(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind==prices.size() || cap==0){ //days exhauseted
            return 0;      //capacity exhausted
        }
        
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        
        int profit=0;
        if(buy==0){//can buy
            int buying=-prices[ind]+f(ind+1,1,cap,prices,dp);//cap same -->only descreases when transaction is complete
            int notbuy=f(ind+1,0,cap,prices,dp);
            profit=max(buying,notbuy);
        }
        
        if(buy==1){//cannot buy-->just allowed to sell
            int sell=prices[ind]+f(ind+1,0,cap-1,prices,dp);//cap-1-->transaction complete
            int notsell=f(ind+1,1,cap,prices,dp);
            profit=max(sell,notsell);
        }
        return dp[ind][buy][cap]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
       //3D DP
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        
        return f(0,0,2,prices,dp);//buy 1 in starting can buy
    }



    //    TABULATION
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
       //3D DP
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
      
        //base case 1 cap==0
        for(int ind=0;ind<n;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0]=0;
            }
        }
        //base case 2 ind==n
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n][buy][cap]=0;
            }
        }
        
        int profit=0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==0){//can buy
                        int buying=-prices[ind]+dp[ind+1][1][cap];
                        int notbuy=dp[ind+1][0][cap];
                        profit=max(buying,notbuy);
                    }
                    else if(buy==1){//cannot buy
                        int sell=prices[ind]+dp[ind+1][0][cap-1];
                        int notsell=dp[ind+1][1][cap];
                        profit=max(sell,notsell);
                    }
                    dp[ind][buy][cap]=profit;
                }
            }
        }
        return dp[0][0][2];
    }