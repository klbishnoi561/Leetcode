// class Solution {
// public:
// //Memoization
//     int n, total;
    
//     void solve(int i, int cnt, int sum,
//                vector<int>& arr,
//                vector<vector<int>>& ans,
//                unordered_set<long long>& dp) {

//         if (cnt > n) return;

//         if (i == arr.size()) {
//             ans[cnt].push_back(sum);
//             return;
//         }

//         long long key = ((long long)i << 40) |
//                         ((long long)cnt << 32) |
//                         (unsigned int)sum;

//         if (dp.count(key)) return;

//         dp.insert(key);

//         // take
//         solve(i + 1, cnt + 1, sum + arr[i],
//               arr, ans, dp);

//         // not take
//         solve(i + 1, cnt, sum,
//               arr, ans, dp);
//     }

//     int minimumDifference(vector<int>& nums) {

//         n = nums.size() / 2;

//         for (int x : nums)
//             total += x;

//         vector<int> left(nums.begin(), nums.begin() + n);
//         vector<int> right(nums.begin() + n, nums.end());

//         vector<vector<int>> l(n + 1);
//         vector<vector<int>> r(n + 1);

//         unordered_set<long long> dp1, dp2;

//         solve(0, 0, 0, left, l, dp1);
//         solve(0, 0, 0, right, r, dp2);

//         for (int i = 0; i <= n; i++)
//             sort(r[i].begin(), r[i].end());

//         int ans = INT_MAX;

//         for (int cnt = 0; cnt <= n; cnt++) {

//             int need = n - cnt;

//             for (int s1 : l[cnt]) {

//                 int target = total / 2 - s1;

//                 auto it = lower_bound(
//                     r[need].begin(),
//                     r[need].end(),
//                     target
//                 );

//                 if (it != r[need].end()) {
//                     int sum1 = s1 + *it;
//                     ans = min(ans, abs(total - 2 * sum1));
//                 }

//                 if (it != r[need].begin()) {
//                     --it;

//                     int sum1 = s1 + *it;
//                     ans = min(ans, abs(total - 2 * sum1));
//                 }
//             }
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        int total = 0;

        for (int x : nums)
            total += x;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> l(n + 1);
        vector<vector<int>> r(n + 1);

        l[0].push_back(0);
        r[0].push_back(0);

        // LEFT
        for (int x : left) {

            for (int cnt = n - 1; cnt >= 0; cnt--) {

                int sz = l[cnt].size();

                for (int j = 0; j < sz; j++) {

                    l[cnt + 1].push_back(
                        l[cnt][j] + x
                    );
                }
            }
        }

        // RIGHT
        for (int x : right) {

            for (int cnt = n - 1; cnt >= 0; cnt--) {

                int sz = r[cnt].size();

                for (int j = 0; j < sz; j++) {

                    r[cnt + 1].push_back(
                        r[cnt][j] + x
                    );
                }
            }
        }

        for (int i = 0; i <= n; i++)
            sort(r[i].begin(), r[i].end());

        int ans = INT_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {

            int need = n - cnt;

            for (int s1 : l[cnt]) {

                int target = total / 2 - s1;

                auto it = lower_bound(
                    r[need].begin(),
                    r[need].end(),
                    target
                );

                if (it != r[need].end()) {

                    int sum1 = s1 + *it;

                    ans = min(
                        ans,
                        abs(total - 2 * sum1)
                    );
                }

                if (it != r[need].begin()) {

                    --it;

                    int sum1 = s1 + *it;

                    ans = min(
                        ans,
                        abs(total - 2 * sum1)
                    );
                }
            }
        }

        return ans;
    }
};