class Solution {
public:
//memoization  (practice ke time tabulation karna hai khud se)
    int solve(int i,int j,int n,int m,vector<vector<int>>& dp,vector<vector<int>>& arr){
        if(i==n-1 && j==m-1) return arr[i][j];
        if(i<0 || i>=n || j<0 || j>=m) return 1e8;
        if(dp[i][j]!=-1) return dp[i][j];
        int c1 = arr[i][j]+solve(i+1,j,n,m,dp,arr); // down
        int c2 = arr[i][j]+solve(i,j+1,n,m,dp,arr); // right
        return dp[i][j] = min(c1,c2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,dp,grid);
    }
};