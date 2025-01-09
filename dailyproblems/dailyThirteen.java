class Solution {
    public int maxProfit(int[] prices) {
        int best = 0;
        int hold = 0;

        for(int i = 0; i < prices.length - 1; i++){
            for(int j = i; j < prices.length; j++){
                if(prices[j] > prices[i] && prices[j] > hold){
                    hold = j;
                }
            }
        }
        return hold;
    }
}
