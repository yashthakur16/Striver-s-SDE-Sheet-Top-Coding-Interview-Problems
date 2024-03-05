class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minprice=prices[0];
       int profit=0;

       for(int i=1;i<prices.size();i++)
       {
           profit=max(prices[i]-minprice,profit);
           minprice=min(minprice,prices[i]);
       }

        return profit;
    }
};
