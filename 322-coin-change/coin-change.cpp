class Solution { 
public: 
    int solve(int i,int n,vector<int>& arr,int amt,vector<vector<int>>& dp){ 
        if(amt==0) return 0; 
        if(amt<0) return 1e9; 
        if(i==n) return 1e9; 

        if(dp[i][amt]!=-1) return dp[i][amt];

        int c1 = 1e9;
        if(amt>=arr[i])
            c1 = 1+solve(i,n,arr,amt-arr[i],dp);

        int c2 = solve(i+1,n,arr,amt,dp);

        return dp[i][amt] = min(c1,c2);
    } 

    int coinChange(vector<int>& coins, int amount) { 
        int n = coins.size(); 
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = solve(0,n,coins,amount,dp);

        if(ans>=1e9) return -1;
        return ans;
    } 
};