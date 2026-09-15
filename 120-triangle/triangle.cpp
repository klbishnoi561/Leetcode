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
// 1. Memoization

// Tumhare memoization mein state (i, j) hai.

// Number of states ≈ n²/2, aur har state mein constant work ho raha hai.

// TC: O(n²)
// SC: O(n²) → DP table
// Recursion Stack: O(n)

// So interview mein:

// Time: O(n²)
// Space: O(n²) + O(n) recursion stack = O(n²)

// 2. Tabulation

// Tumhare tabulation mein:

// for(int i=n-1; i>=0; i--)
//     for(int j=0; j<=i; j++)

// Total iterations:

// 1 + 2 + 3 + ... + n = O(n²)

// TC: O(n²)
// SC: O(n²) → DP table
// No recursion stack

// So:

// Time: O(n²)
// Space: O(n²)

// Interview mein ekdum short:
// Approach	Time	Space
// Memoization	O(n²)	O(n²)
// Tabulation	O(n²)	O(n²)

// Important: Agar interviewer specifically bole "auxiliary space", to memoization mein recursion stack ko separately mention karna: O(n²) DP + O(n) stack.