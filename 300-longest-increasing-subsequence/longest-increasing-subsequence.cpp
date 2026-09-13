
//MEMOIZATION METHOD code
class Solution {
public:
    int solve(int i,int pre,vector<int>& nums,vector<vector<int>>& dp,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][pre+1]!=-1) return dp[i][pre+1];
        if(pre==-1 || nums[i]>nums[pre]){
            int c1 = 1 + solve(i+1,i,nums,dp,n);
            int c2 = solve(i+1,pre,nums,dp,n);
            return dp[i][pre+1] = max(c1,c2);
        }
        else {
            return dp[i][pre+1] = solve(i+1,pre,nums,dp,n);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int pre = -1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,pre,nums,dp,n);
    }
};