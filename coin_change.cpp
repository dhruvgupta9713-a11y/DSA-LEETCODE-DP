class Solution {
public:

   vector<int>dp;
    int solve(int amount, vector<int>& coins) {
        
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

      
        if (dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;

        for (int coin : coins) {
            int res = solve(amount - coin, coins);

            if (res != INT_MAX) {
                mini = min(mini, 1 + res);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
         dp.resize(amount + 1, -1);


        int ans = solve(amount, coins);

        return (ans == INT_MAX) ? -1 : ans;
    }
};