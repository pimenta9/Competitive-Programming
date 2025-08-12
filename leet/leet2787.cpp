// ACCEPTED!

class Solution {
public:
    int numberOfWays(int n, int x)
    {
        vector<int> powers;

        for (int i = 1;; i++) {
            int p = pow(i, x);

            if (p > n)
                break;

            powers.push_back(p);
        }

        int m = powers.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % 1000000007;

                int next_j = j + powers[i];
                if (next_j <= n)
                {
                    dp[i+1][next_j] = (dp[i+1][next_j] + dp[i][j]) % 1000000007;
                }
            }
        }

        return dp[m][n];
    }
};
