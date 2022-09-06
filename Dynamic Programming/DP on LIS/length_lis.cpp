
#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION


int f(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
        
        if(ind==nums.size())  return 0;//base case
        
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        
        int notpick = f(ind+1,prev,nums,dp);//prev remain same-> because we are not picking anything
        
           int pick=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            pick=1+f(ind+1,ind,nums,dp);//ind is the new prev
        }
        
        return dp[ind][prev+1]=max(notpick,pick);
        
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        //cannot store -1 ind in 2d array becuase indexing starts from 0
        //prev+1 is done-->COORDINATE CHANGE

        vector<vector<int>>dp(n,vector<int>(n+1,-1));//prev ind shift by 1
        return f(0,-1,nums,dp);//ind,prev
    }