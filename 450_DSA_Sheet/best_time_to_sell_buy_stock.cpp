class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX; // minimum buying price
        int maxProfit = 0; // maximum profit earned
        for (auto it : prices){
            mini = min(mini,it); // minimum buying price to get maximum profit
            maxProfit = max(maxProfit,(it-mini)); // maximum profit (selling - buying) got when minimum buying price is fixed.
        }
        return maxProfit;
    }
};