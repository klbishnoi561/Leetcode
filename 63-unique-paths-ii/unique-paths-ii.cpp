class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& dp,vector<vector<int>>& arr){
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int c1=0;
        int c2=0;
        if(i+1<n && arr[i+1][j]!=1) c1 = solve(i+1,j,n,m,dp,arr);
        if(j+1<m && arr[i][j+1]!=1) c2 = solve(i,j+1,n,m,dp,arr);
        return dp[i][j]=c1+c2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,dp,obstacleGrid);
    }
};