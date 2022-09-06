#include "bits/stdc++.h"
using namespace std;


int lcs(string s1,string s2){
        int n=s1.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
    
    int longestpalindorme(string s1){
        
        int n=s1.length();
        
        
        
        string s2=s1;
        
        reverse(s2.begin(),s2.end());
        
        //now find lcs of s1 and s2 that will be longest palindroic subsequence
        return lcs(s1,s2);
    }
    
    int minInsertions(string s) {
        
        int n=s.length();
        return n-longestpalindorme(s);
    }