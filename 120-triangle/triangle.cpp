class Solution {
public:
//MEMOIZATION(TABULATION KHUD SE KARUGA REVISION KE TIME)
    // int solve(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>>& dp){
    //     if(i==n) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int d1 = solve(i+1,j,n,arr,dp)+arr[i][j];
    //     int d2 = solve(i+1,j+1,n,arr,dp)+arr[i][j];
    //     return dp[i][j] = min(d1,d2);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n);
    //     for(int i=0;i<n;i++){
    //         vector<int> t(i+1,-1);
    //         dp[i] = t;
    //     }
    //     return solve(0,0,n,triangle,dp);
    // }



// TABULATION
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1);
        for(int i=0;i<=n;i++){
            vector<int> t(i+1,0);
            dp[i] = t;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j] = min(dp[i+1][j]+arr[i][j],dp[i+1][j+1]+arr[i][j]);
            }
        }
        return dp[0][0];
    }
};