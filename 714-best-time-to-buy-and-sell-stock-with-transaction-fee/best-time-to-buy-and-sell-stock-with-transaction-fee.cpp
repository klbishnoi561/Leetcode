class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] < buy) {
                buy = prices[i];
            }

            else if(prices[i] > buy + fee) {
                profit += prices[i] - buy - fee;
                buy = prices[i] - fee;
            }
        }

        return profit;
    }
};