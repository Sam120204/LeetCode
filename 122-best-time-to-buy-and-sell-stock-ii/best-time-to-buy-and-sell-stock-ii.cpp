class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int j = 1;
        while(j<prices.size()){
            if(prices[j] > prices[j-1]){
                sum += prices[j] - prices[j-1];
            }
            j++;
        }
        return sum;
    }
};