//problem stmt:   Given two strings s1 and s2  --> tell no. of times s2 appear in s1

#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION 

int f(int i,int j,string s,string t,vector<vector<int>>&dp){  //can remove tle by taking &s and &t
        //if everything is matched-->j exhausted
        if(j<0){
            return 1;
        }
        
        //if there is still matching to be done-->i exhausted //but j has elemnts left
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            //considering element// not considering element
            return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j]=f(i-1,j,s,t,dp);
        }
    }
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }



//TABULATION

 int prime = 1e9+7;
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        //1 based indexing
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;//j exhauseted
        }
        for(int j=1;j<=m;j++){  //j starts from 1 because for j=0 we already put in prev loop 
            dp[0][j]=0;  //i exhausted
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= (dp[i-1][j-1]+dp[i-1][j])%prime;
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }