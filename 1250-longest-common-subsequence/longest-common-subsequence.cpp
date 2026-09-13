class Solution {
public:
    // recursion
    // int solve(int i,int j,string & s1,string & s2,int n,int m){
    //     if(i==n || j==m) return 0;
    //     if(s1[i]==s2[j]) return 1 + solve(i+1,j+1,s1,s2,n,m);
    //     else {
    //         int c1 = solve(i+1,j,s1,s2,n,m);
    //         int c2 = solve(i,j+1,s1,s2,n,m);
    //         return max(c1,c2);
    //     }
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //    int n = text1.size();
    //    int m = text2.size();
    //    return solve(0,0,text1,text2,n,m); 
    // }




    // MEMOIZATION
    int solve(int i,int j,string& s1,string& s2,vector<vector<int>>& dp,int n,int m){
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = 1 + solve(i+1,j+1,s1,s2,dp,n,m);
        int c1 = solve(i+1,j,s1,s2,dp,n,m);
        int c2 = solve(i,j+1,s1,s2,dp,n,m);
        return dp[i][j]=max(c1,c2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,text1,text2,dp,n,m); 
    }
    // int longestCommonSubsequence(string text1, string text2) {
        
    // }
}; 