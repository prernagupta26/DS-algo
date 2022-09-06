
#include "bits/stdc++.h"
using namespace std;


//memoization


int f(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }

    if(dp[n]!=-1){//computed earlier  //step3 checking
        return dp[n];
    }

    return dp[n]=f(n-1,dp)+f(n-2,dp);//step 2 storing
}


int main(){
    int n=5;
    vector<int> dp(n+1,-1);  //step 2 declaration

    cout<<f(n,dp);
    return 0;
}
