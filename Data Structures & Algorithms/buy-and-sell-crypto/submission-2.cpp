class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minprice = prices[0];
        int maxpro = 0;
        for(int i =0;i<n;i++){
            minprice = min(minprice , prices[i]);
            int profit = prices[i] - minprice;
            maxpro = max(maxpro,profit);
        }
        return maxpro;
    }
};
