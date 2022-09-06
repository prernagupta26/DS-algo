#include "bits/stdc++.h"
using namespace std;


                                     // VARIABLE START AND VARIABLE ENDING


//nxm matrix

//MEMOIZATION
int f(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>&dp){
          int n=matrix.size();
       int m = matrix[0].size();
                  //reached out of cloumn
        if(j<0 || j>=m){//out of boundary case
            return -1e9; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
         //base case
        //reaching destination
        if(i==0){
            return matrix[0][j];
        }
        
        int ld=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int up=matrix[i][j]+f(i-1,j,matrix,dp);
        int rd=matrix[i][j]+f(i-1,j+1,matrix,dp);
        
        return dp[i][j]=max(ld,max(up,rd));
    }
int getMaxPathSum(vector<vector<int>> &matrix)
{
     int n=matrix.size();
    int m = matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int maxi=-1e9;
        for(int j=0;j<m;j++){
            int ans=f(n-1,j,matrix,dp);
            maxi=max(maxi,ans);
        }
        return maxi;
}