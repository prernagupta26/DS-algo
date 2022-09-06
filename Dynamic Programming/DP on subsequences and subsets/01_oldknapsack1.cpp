 #include "bits/stdc++.h"
using namespace std;
  
  

  //MEMOIZATION
  
  //declaring global variable
    int dp[1001][1001];
    
    
    
    
   int solve(int W, int wt[], int val[], int n){
       //write base case
       
       if(n==0 || W==0){
           return 0;
       }
       
       
       
       if(dp[n][W]!=-1){
           return dp[n][W];
       }
       
       if(wt[n-1]<=W){
           //we have 2 choices to include or not include
           
           return dp[n][W]=max(val[n-1]+solve(W-wt[n-1],wt,val,n-1) , solve(W,wt,val,n-1));
       }
       
       else{//wight of item more than capacity
       //only one choice-- not include
           return dp[n][W]=solve(W,wt,val,n-1);
       }
   }
   
   
   
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof(dp));
       return solve(W,wt,val,n);
    }





    //TABULATION

     
    int knapSack2(int W, int wt[], int val[], int n) 
    { 
        
        
         vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        
        //for rest of array  //put i instead of n and j instead of W
      for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                
                int not_pick=dp[i-1][j];
                int pick=INT_MIN;
                
                
                if(wt[i-1]<=j){
                    
                    pick=val[i-1]+dp[i-1][j-wt[i-1]];
                   
                }
                
                dp[i][j]=max(pick,not_pick);
                
            }}
            
            return dp[n][W];
       
    }