// ACCEPTED!

class Solution {
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> dp(k + maxPts);
        double sum = 0;
        for (int i = k; i < k + maxPts; i++)
        {
            if (i <= n)
                dp[i] = 1;
            else
                dp[i] = 0;

            sum += dp[i];
        }

        for (int i = k-1; i >= 0; i--)
        {
            dp[i] = sum/maxPts;
            sum -= dp[i + maxPts];
            sum += dp[i];
        }

        return dp[0];
    }
};
