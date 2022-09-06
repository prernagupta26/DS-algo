#include "bits/stdc++.h"
using namespace std;



//RECURSION  //TC-->O(2^(mxn))
            //SC-->O((m-1)+(n-1))-->path length-->stack space

    int f(int i,int j){
        if(i==0 && j==0){//destination reached
            return 1;
        }
        if(i==-1 || j==-1){//excedding boundary
            return 0;
        }
        
        int up=f(i-1,j);
        int left=f(i,j-1);
        
        return up+left;
    }
    
    int uniquePaths(int m, int n) {
        int ans;
        ans=f(m-1,n-1);
        return ans;
    }



    //MEMOIZATION

     //TC-->O(mxn)
          //stack space   //dp array
    //SC-->O((n-1)+(m-1)) + O(nxm)


    int f(int i,int j, vector<vector<int>>&dp){
        if(i==0 && j==0){//destination reached
            return 1;
        }
        if(i==-1 || j==-1){//excedding boundary
            return 0;
        }
        //step2--> check if value is used before
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        
        return dp[i][j]=up+left;
    }
    
    int uniquePaths(int m, int n) {
        
        //step1 declare dp array
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans;
        ans=f(m-1,n-1,dp);
        return ans;
    }


    //TABULATION

     //TC-->O(mxn)
           //dp array
    //SC-->  O(nxm)    //stack space removed     
    
    int uniquePaths(int m, int n) {
        
        //step1 declare dp array
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               //base case
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
               dp[i][j]=up+left;
           }
           
       }
        return dp[m-1][n-1];
    }