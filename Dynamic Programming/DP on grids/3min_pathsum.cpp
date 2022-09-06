#include "bits/stdc++.h"
using namespace std;

//RECURSION

class Solution {
public:
    
    int f(int i,int j,vector<vector<int>>& grid){
        if(i==0 && j==0 ){//destination reached
            return grid[0][0];
        }
        
        if(i<0 || j<0){//boundaries of grid crossed
            return 1e9;//returning maximum value so it is not considered
        }
        
        int up=grid[i][j]+f(i-1,j,grid);
        int left=grid[i][j]+f(i,j-1,grid);
        
        return min(up,left);
    }   

    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();//row
        int n=grid[0].size();//coulmn
        
        return f(m-1,n-1,grid);
    }
};


   
    //MEMOIZATION
    int f(int i,int j,vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==0 && j==0 ){//destination reached
            return grid[0][0];
        }
        
        if(i<0 || j<0){//boundaries of grid crossed
            return 1e9;//returning maximum value so it is not considered
        }
        
        if(dp[i][j]!=-1){//step2 cheching if value of dp array previously used
            return dp[i][j];
        }
        
        int up=grid[i][j]+f(i-1,j,grid,dp);
        int left=grid[i][j]+f(i,j-1,grid,dp);
        
        return dp[i][j]=min(up,left);//storing the curr val in dp array
    }   

    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();//row
        int n=grid[0].size();//coulmn
        
        vector<vector<int>>dp(m,vector<int>(n,-1));//step1 create dp array intialize with -1
        
        return f(m-1,n-1,grid,dp);
    }


     //TABULATION (removing stack space)
 
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();//row
        int n=grid[0].size();//coulmn
        
        vector<vector<int>>dp(m,vector<int>(n,0));//step1 create dp array intialize with 0
        
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                //base case
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    
                }
                else{
                int up=grid[i][j],left=grid[i][j];
                
                if(i>0){
                    up+=dp[i-1][j];
                }
                else{
                    up+=1e9;
                }
                if(j>0){
                    left+=dp[i][j-1];
                }
                else{
                     left+=1e9;
                }
                
                dp[i][j]=min(up,left);
                
            }
            }
        }
        return dp[m-1][n-1];
        
    }