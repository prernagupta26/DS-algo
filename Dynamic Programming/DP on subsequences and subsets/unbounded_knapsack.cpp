   #include "bits/stdc++.h"
using namespace std;

//infinite supply pattern
int f(int ind,int cap, vector<int> &val, vector<int> &wt, vector<vector<int>>&dp){
    //base case
    if(ind==0){
        return ((int)(cap/wt[0]))*val[0];
    }
    if(dp[ind][cap]!=-1){
        return dp[ind][cap];
    }
    
    int notpick=f(ind-1,cap,val,wt,dp);
    int pick=INT_MIN;
    if(cap>=wt[ind]){
        pick=val[ind]+f(ind,cap-wt[ind],val,wt,dp);
    }
    
    return dp[ind][cap]=max(pick,notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}


//tabulation
int unboundedKnapsack(int n, int cap, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(cap+1,0));
    
    for(int i=wt[0];i<=cap;i++){
         dp[0][i]=((int)(i/wt[0]))*val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=cap;j++){
            int notpick=dp[i-1][j];
            int pick=INT_MIN;
            if(j>=wt[i]){
                pick=val[i]+dp[i][j-wt[i]];
            }
            dp[i][j]=max(pick,notpick);
        }
    }
    return dp[n-1][cap];
}
