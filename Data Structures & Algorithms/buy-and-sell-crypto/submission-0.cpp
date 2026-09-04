class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int min_price = prices[0];

        for (int p : prices) {
            maxP = max(maxP, p - min_price);
            min_price = min(min_price, p);
        }

        return maxP;
    }
};
