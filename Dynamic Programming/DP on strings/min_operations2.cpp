#include "bits/stdc++.h"
using namespace std;

//OPERATIONS-> INSERT, DELETE, REPLACE

 void minDistanceIterative(string word1, string word2, vector<vector<int>> &dp) {
        for(int i=0; i<=word1.size(); ++i) 
            dp[i][0] = i;
        for(int j=0; j<=word2.size(); ++j)
            dp[0][j] = j;
        
        for(int i=1; i<=word1.size(); ++i) {
            for(int j=1; j<=word2.size(); ++j) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    int insertChar = dp[i][j-1];
                    int deleteChar = dp[i-1][j];
                    int replaceChar = dp[i-1][j-1];
                    dp[i][j] = 1 + min({insertChar, deleteChar, replaceChar});
                }
            }
        }
    }

    int minDistance(string word1, string word2) {
        /*
        For Recursive:
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        minDistanceRecursive(word1, word2, dp, 0, 0);
        */
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        minDistanceIterative(word1, word2, dp);
        return dp[word1.size()][word2.size()];
    }
