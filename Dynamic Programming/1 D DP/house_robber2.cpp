 #include "bits/stdc++.h"
using namespace std;

//houses in circular oder // first and last house house cannot be together

long long int rob(vector<int>& nums) {
        
       long long int n=nums.size();
        long long int prev=nums[0];
        long long int prev2=0;
        
        for(int i=1;i<n;i++){
            long long int pick=nums[i];
                if(i>1){
                    pick+=prev2;
                }
            long long int notpick=prev;
            
            long long int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;

    }

long long int houseRobber(vector<int>& nums)
{
    
   vector<int>temp1,temp2;
    long long int n=nums.size();
    if(n==1){
        return nums[0];
    }
    for(int i=0;i<n;i++){
        if(i!=0){    //apart for first element push everything
            temp1.push_back(nums[i]);
        }
        if(i!=n-1){  //apart from last element push everything 
            temp2.push_back(nums[i]);  
        }
    }
        return max(rob(temp1),rob(temp2));
    
}