class Solution {
public:
//RECURSION
    // int solve(int i,int k,int n,vector<int>& arr){
    //     if(k==0 || i==n) return 0;
    //     if(k==4 || k==2){ // only you can buy
    //         int c1 = solve(i+1,k-1,n,arr)-arr[i]; //buy
    //         int c2 = solve(i+1,k,n,arr); // buy not
    //         return max(c1,c2);
    //     }
    //     else{ // sell or sell not
    //         int d1 = solve(i+1,k-1,n,arr)+arr[i]; //sell
    //         int d2 = solve(i+1,k,n,arr); //sell not
    //         return max(d1,d2);
    //     }
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int k = 4;
    //     return solve(0,k,n,prices);
    // }
//MEMOIZATION
    int solve(int i,int k,int n,vector<int>& arr,vector<vector<int>>& dp){
        if(k==0 || i==n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==4 || k==2){ // only you can buy
            int c1 = solve(i+1,k-1,n,arr,dp)-arr[i]; //buy
            int c2 = solve(i+1,k,n,arr,dp); // buy not
            return dp[i][k]=max(c1,c2);
        }
        else{ // sell or sell not
            int d1 = solve(i+1,k-1,n,arr,dp)+arr[i]; //sell
            int d2 = solve(i+1,k,n,arr,dp); //sell not
            return dp[i][k]=max(d1,d2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 4;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(0,k,n,prices,dp);
    }
};