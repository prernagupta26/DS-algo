#include "bits/stdc++.h"
using namespace std;

//total unique paths with obstacle

//memoization
   int f(int i,int j, vector<vector<int>>& mat, vector<vector<int>>&dp){
        if(i>=0 && j>=0 && mat[i][j]==-1){
            return 0;
        }
        
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        
       
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up=f(i-1,j,mat,dp);
        int left=f(i,j-1,mat,dp);
        
        return dp[i][j]=(up+left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        
        int m=mat.size();  //rows
        int n=mat[0].size(); //columns
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        
        return f(m-1,n-1,mat,dp);
    }



    //tabulation
        int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        
        int m=mat.size();  //rows
        int n=mat[0].size(); //columns
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                //base conditions
                if(i>=0 && j>=0 && mat[i][j]==1){
                 dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                int up=0,left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=left+up;
                
                
            }
        }
        
        
        return dp[m-1][n-1];
    }