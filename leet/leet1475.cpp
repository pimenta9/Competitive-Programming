// ACCEPTED!

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        for (int i = 0; i < prices.size(); i++)
        {
            int discount = 0;

            int j;
            for (j = i + 1; j < prices.size() and prices[j] > prices[i]; j++);
            
            if (j < prices.size())
                discount = prices[j];

            prices[i] -= discount;
        }
        
        return prices;
    }
};
