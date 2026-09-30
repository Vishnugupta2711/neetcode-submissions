class Solution {
public:
    int LCS(const string& text1 ,int m , const string& text2,int n , vector<vector<int>>& dp){
        if(m == 0 || n == 0){
            return 0;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(text1[m-1] == text2[n-1]){
            dp[m][n] = 1 + LCS(text1 , m-1,text2,n-1,dp);
        }
        else{
            dp[m][n] = max(LCS(text1,m-1,text2,n,dp),LCS(text1,m,text2,n-1,dp));
        }
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return LCS(text1,m,text2,n,dp);
    }
};
