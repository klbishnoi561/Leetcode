// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(n);
      for(int i=0;i<n;i++){
        ans[i] = 1;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
            ans[i] = max(ans[i],ans[j]+1);
            }

        }
      }
      int a = INT_MIN;
      for(int i=0;i<n;i++){
        a = max(a,ans[i]);
      }
      return a;

    }
};
