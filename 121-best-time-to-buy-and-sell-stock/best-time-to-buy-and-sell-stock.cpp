class Solution {
public:
//RECURSION
    // int solve(int i,vector<int>& arr,int n,int k){
    //     if(i==n || k==0) return 0;
    //     // k==2 you can buy aur buy not
    //     if(k==2){
    //         int c1 = solve(i+1,arr,n,k-1)-arr[i]; // buy
    //         int c2 = solve(i+1,arr,n,k);  // buy not
    //         return max(c1,c2);
    //     }
    //     else { // else means k==1 then you can only sell or sell not
    //         int d1 = solve(i+1,arr,n,k-1) + arr[i]; // sell
    //         int d2 = solve(i+1,arr,n,k); // sell not
    //         return max(d1,d2);
            
    //     }
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int k = 2;
    //     return solve(0,prices,n,k);
    // }



// MEMOIZATION
    int solve(int i,vector<int>& arr,int n,int k,vector<vector<int>>& dp){
        if(i==n || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        // k==2 you can buy aur buy not
        if(k==2){
            int c1 = solve(i+1,arr,n,k-1,dp)-arr[i]; // buy
            int c2 = solve(i+1,arr,n,k,dp);  // buy not
            return dp[i][k]=max(c1,c2);
        }
        else { // else means k==1 then you can only sell or sell not
            int d1 = solve(i+1,arr,n,k-1,dp) + arr[i]; // sell
            int d2 = solve(i+1,arr,n,k,dp); // sell not
            return dp[i][k]=max(d1,d2);
            
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(0,prices,n,k,dp);
    }
};