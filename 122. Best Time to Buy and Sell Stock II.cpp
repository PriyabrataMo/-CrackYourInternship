class Solution
{
public:
    int func(vector<int> &prices, int ind, int b, vector<vector<int>> &dp)
    {

        if (ind == prices.size() - 1)
        {
            if (b == 1)
                return 0;
            return prices[ind];
        }
        int profit;
        if (dp[ind][b] != -1)
            return dp[ind][b];
        if (b == 1)
        {
            profit = max((-prices[ind] + func(prices, ind + 1, 0, dp)), func(prices, ind + 1, 1, dp));
        }
        else
        {
            profit = max((prices[ind] + func(prices, ind + 1, 1, dp)), func(prices, ind + 1, 0, dp));
        }
        return dp[ind][b] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int b = 0; b <= 1; b++)
            {
                int profit;
                if (b == 1)
                {
                    profit = max((-prices[ind] + dp[ind + 1][0]), dp[ind + 1][1]);
                }
                else
                {
                    profit = max((prices[ind] + dp[ind + 1][1]), dp[ind + 1][0]);
                }
                dp[ind][b] = profit;
            }
        }

        return dp[0][1];
    }
};