#include "bits/stdc++.h"
using namespace std;


                                           //FIXED STARTING AND VARIABLE ENDING

//MEMOIZATION
 //MEMOIZATION
    int f(int i,int j, vector<vector<int>>& triangle , vector<vector<int>>&dp){
          int m=triangle.size();//row
        int n=triangle[0].size();//column
        
        if(i==m-1){//reached destination row
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int down=triangle[i][j] + f(i+1,j,triangle,dp);
        int diagnol=triangle[i][j]+f(i+1,j+1,triangle,dp);
        
        return dp[i][j]=min(down,diagnol);
    }
     
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        
        int m=triangle.size();//row
        int n=triangle[0].size();//column
        
        vector<vector<int>>dp(m,vector<int>(m,-1));//step 1 create dp array and initialize with -1
        
        return f(0,0,triangle,dp);
    }


    //TABULATION -->SC-->O(nxn)  tc=O(nxn)

     int minimumTotal(vector<vector<int>>& triangle) {
        
        
        
        int m=triangle.size();//row
       
        
        vector<vector<int>>dp(m,vector<int>(m,-1));//step 1 create dp array and initialize with -1
       
        //no. of columns is eqaul to no. of rows 
        //suppose no. of rows are 5 -->there are 5 elements -->5 columns
        //m different base cases//there are m columns in mth row 
        //there will be m different cases for each column
        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j];
            
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diagnol=triangle[i][j]+dp[i+1][j+1];
                
                dp[i][j]=min(down,diagnol);
            }
        }
        return dp[0][0];
    }