       #include "bits/stdc++.h"
using namespace std;
    
    //MEMOIZATION
    int f(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
        //base case
        if(ind1<0 || ind2<0){//index gets negative
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        
        if(s[ind1]==t[ind2]){//matching
            return dp[ind1][ind2]=1+f(ind1-1,ind2-1,s,t,dp);//moving both indexes
        }
        
        else
        //not matching
        return dp[ind1][ind2]=max(f(ind1-1,ind2,s,t,dp),f(ind1,ind2-1,s,t,dp));//moving only one index at a time and returning their max
    }
    
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }



    //TABULATION -->right shifting ofi indexes for base cases
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       
        //BASE CASE
        //ind1<0-->ind1==0(on right shift)
        for(int i=0;i<=m;i++){//for any index of index2
            dp[0][i]=0;
        }
        
        for(int i=0;i<=n;i++){//ind2==0 //for any index of index1
            dp[i][0]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s[i-1]==t[j-1]){//matching//right shift thats why i-1,j-1
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }