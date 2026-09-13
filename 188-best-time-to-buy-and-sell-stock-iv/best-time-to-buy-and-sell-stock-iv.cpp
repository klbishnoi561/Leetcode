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
    int solve(int i,int k,vector<int>& arr,int n,vector<vector<int>>& dp){
        if(i==n || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k%2==0){ // buy
            int c1 = solve(i+1,k-1,arr,n,dp)-arr[i]; //buy
            int c2 = solve(i+1,k,arr,n,dp); // buy not
            return dp[i][k]=max(c1,c2);
        }
        else{
            int d1 = solve(i+1,k-1,arr,n,dp)+arr[i]; // sell
            int d2 = solve(i+1,k,arr,n,dp); // not sell
            return dp[i][k]=max(d1,d2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
        return solve(0,2*k,prices,n,dp);
    }
};