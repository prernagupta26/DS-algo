 #include "bits/stdc++.h"
using namespace std;
   //leetcode -->> HOUSE ROBBER




   //Recursion //ONLY
    int f(int ind,vector<int>& nums){
        if(ind==0){ //when reached 0 pick that element-->at 0th index
            return nums[ind];
        }
        
        if(ind<0){
            return 0;
        }
        
        int pick=nums[ind]+f(ind-2,nums);
        
        int notpick=f(ind-1,nums);
        
        return max(pick,notpick);
        
    }
    
    
    int rob(vector<int>& nums) {
        
        
        return f(nums.size()-1,nums);
    }


 //MEMOIZATION
    int f(int ind,vector<int>& nums,vector<int>&dp){
        
        
        if(ind==0){
            return nums[ind];
        }
        
        if(ind<0){
            return 0;
        }
        
        if(dp[ind]!=-1){ //add if condition
            return dp[ind];
        }
        
        int pick=nums[ind]+f(ind-2,nums,dp);
        
        int notpick=f(ind-1,nums,dp);
        
        return dp[ind]=max(pick,notpick);//check if previously computed
        
    }
    
    
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);//step1-->create dp array

        return f(nums.size()-1,nums,dp);
    }


    //TABULATION SC-->O(N) ,, TC-->O(N)

     int rob(vector<int>& nums) {
        
       int n=nums.size();
        
       
        if(n==1){
            return nums[0];
        }
        
        
         vector<int>dp(n);  //step1-->crerate dp array
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
         
        
        
        for(int i=2;i<n;i++){
            int pick=nums[i]+dp[i-2];
            int notpick=dp[i-1];
            
            dp[i]=max(pick,notpick);
        }
        return dp[n-1]; 
      
    }

    //TABULATION -->FURTHER SPACE OPTIMISATION ,, SC-->O(1)

    
    int rob(vector<int>& nums) {
        
       int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        
        
        for(int i=1;i<n;i++){
            int pick=nums[i];
                if(i>1){
                    pick+=prev2;
                }
            
            int notpick=prev;
            
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
      
    }