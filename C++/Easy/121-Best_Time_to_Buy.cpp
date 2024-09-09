/*121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Start with profit 0 and 1st element in prices
        int profit = 0;
        int min = prices[0];

        for(int i=1; i<prices.size(); i++){
        
            // Search for current min 
            if(prices[i] < min){
                min = prices[i];
            }      

            // Compare current and previous profit
            profit = max(profit, prices[i] - min);
        }

        return profit;
    }
};