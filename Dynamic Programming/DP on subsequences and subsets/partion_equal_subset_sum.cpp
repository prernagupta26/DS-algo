 #include "bits/stdc++.h"
using namespace std;
 

 //MEMOIZATION
 bool f(int ind,int target,vector<int>&a,vector<vector<int>>&dp){
        
        if(target==0){
            return true;
        }
        if(ind==0){
            return a[0]==target;
        }
        
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int notpick=f(ind-1,target,a,dp);
        
        int pick=false;
        if(target>=a[ind]){
            pick=f(ind-1,target-a[ind],a,dp);
        }
        
        return dp[ind][target]=pick||notpick;
    }
    
    bool canPartition(vector<int>& nums) {
       
        //we need to find if one subset has sum s/2
        //s/2 --> is our target
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2==1){//sum is odd and we cant devide it
            return false;
        }
        
        int target=sum/2;
        
        //create dp array
         vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
    }




    //TABULATION//eleminate recursion stack space
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2==1){//sum is odd and we cant devide it
            return false;
        }
        int target=sum/2;
        
        //create dp array
         vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        
       //1 //base conditions
        //for every index target is 0
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        //base case
        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }
        
        // dp[0][nums[0]]=true;//target is equal to 0th index element when we reach 0th index element
        
        //2 //run nested loops
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                int notpick=dp[i-1][j];//not picking target remains same
                
                int pick=false;
                if(j>=nums[i]){
                    pick=dp[i-1][j-nums[i]];
                }
                
                dp[i][j]=pick or notpick;
            }
            
        }
        
        return dp[n-1][target];
    }