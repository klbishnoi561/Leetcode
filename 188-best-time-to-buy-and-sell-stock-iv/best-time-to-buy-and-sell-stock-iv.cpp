class Solution {
public:
//RECURSION
    // int solve(int i,int k,vector<int>& arr,int n){
    //     if(i==n || k==0) return 0;
    //     if(k%2==0){ // buy
    //         int c1 = solve(i+1,k-1,arr,n)-arr[i]; //buy
    //         int c2 = solve(i+1,k,arr,n); // buy not
    //         return max(c1,c2);
    //     }
    //     else{
    //         int d1 = solve(i+1,k-1,arr,n)+arr[i]; // sell
    //         int d2 = solve(i+1,k,arr,n); // not sell
    //         return max(d1,d2);
    //     }
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     return solve(0,2*k,prices,n);
    // }


//MEMOIZATION
    // int solve(int i,int k,vector<int>& arr,int n,vector<vector<int>>& dp){
    //     if(i==n || k==0) return 0;
    //     if(dp[i][k]!=-1) return dp[i][k];
    //     if(k%2==0){ // buy
    //         int c1 = solve(i+1,k-1,arr,n,dp)-arr[i]; //buy
    //         int c2 = solve(i+1,k,arr,n,dp); // buy not
    //         return dp[i][k]=max(c1,c2);
    //     }
    //     else{
    //         int d1 = solve(i+1,k-1,arr,n,dp)+arr[i]; // sell
    //         int d2 = solve(i+1,k,arr,n,dp); // not sell
    //         return dp[i][k]=max(d1,d2);
    //     }
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n,vector<int>(2*k+1,-1));
    //     return solve(0,2*k,prices,n,dp);
    //}


//TABULATION
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        k = 2*k;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                if(j%2==0){//buy
                    dp[i][j] = max(dp[i+1][j-1]-arr[i],dp[i+1][j]);
                }
                else{ // sell or sell not
                    dp[i][j] = max(dp[i+1][j-1]+arr[i],dp[i+1][j]);
                }

            }
        }
        return dp[0][k];
    }
};