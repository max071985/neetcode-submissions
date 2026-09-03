class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price, output = 0;
        if (prices.size() == 0) return 0;
        min_price = prices[0];
        for (int price : prices) {
            min_price = min(min_price, price);
            output = max(output, price - min_price);
        }
        return output;
    }
};
