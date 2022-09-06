   #include "bits/stdc++.h"
using namespace std;



//MEMOIZATION
int f(int ind,int target,vector<int>&price,vector<vector<int>>&dp){
   //base case
    if(ind==0){
        return target*price[0];
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int notpick=f(ind-1,target,price,dp);
    int pick=-1e9;
    int rodlength=ind+1;
    if(target>=rodlength){
        pick=price[ind]+f(ind,target-rodlength,price,dp);
    }
    return dp[ind][target]=max(pick,notpick);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
    
}


//TABULATION
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	
    //base case
    for(int i=0;i<=n;i++){
        dp[0][i]=i*price[0];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int notpick=dp[i-1][j];
            int pick=-1e9;
            if(j>=i+1){//rodlength i+1==rodlength
                pick=price[i]+dp[i][j-i-1];
            }
            dp[i][j]=max(pick,notpick);
        }
    }
    return dp[n-1][n];
    
}