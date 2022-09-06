 #include "bits/stdc++.h"
using namespace std;

//code studiio ques

//MEMOIZATION
int f(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        
        for(int task=0;task<3;task++){ //day==0//base case
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1){//check if this subproblem has been previously solved
        return dp[day][last];
    }
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int total_points=points[day][task] + f(day-1,task,points,dp);
            //current task is last for next day
            maxi=max(maxi,total_points);
        }
    }
    return dp[day][last]=maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));//NX4 size
   return f(n-1,3,points,dp);
}