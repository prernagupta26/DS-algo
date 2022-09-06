#include <bits/stdc++.h>

using namespace std;

string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int len=dp[n][m];//length of lcs
        int i=n;
        int j=m;
        
        int index=len-1;
        string ans="";
        
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){ //mmatching then add eigther into ans
                ans+=s1[i-1];
                index--; //lcs length
                i--;//moving diagnolly
                j--;
            }
            //moving towards max
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;   //moving up
            }
            else {
                ans+=s2[j-1];
                j--;  //moving left
            }
        }
        //adding all the remaing elemnts of eigther string which is left
        //only one of the two while loops will run
        
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }